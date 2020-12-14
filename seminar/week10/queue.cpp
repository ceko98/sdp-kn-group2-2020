#ifndef FMI_QUEUE_H_
#define FMI_QUEUE_H_

#include <cassert>
#include <functional>
#include <algorithm>

template <typename T>
class FMIQueue
{
public:
    struct Node
    {
        T data;
        Node* next;
    };

private:
    Node* first;
    Node* last;

    std::function<bool(const T&, const T&)> ord;

    void copy(const FMIQueue<T>& other);
    void clear();

public:
    FMIQueue(std::function<bool(const T&, const T&)> predicate)
        : first(nullptr), last(nullptr), ord(predicate) {}

    FMIQueue(const FMIQueue<T>& other)
        : first(nullptr), last(nullptr)
    {
        copy(other);
    }

    FMIQueue<T>& operator=(const FMIQueue<T>& other)
    {
        if (this != &other)
        {
            clear();
            copy(other);
        }

        return *this;
    }

    ~FMIQueue()
    {
        clear();
    }

    int size();
    bool empty() { return first == nullptr; }
    T& front() { return first->data; }
    void pop();
    void push_back(const T& data);
};

template <typename T>
void FMIQueue<T>::copy(const FMIQueue<T>& other)
{
    ord = other.ord;

    Node* it = other.first;
    while(it != nullptr)
    {
        this->push_back(it->data);
        it = it->next;
    }
}

template <typename T>
void FMIQueue<T>::clear()
{
    while(!empty())
    {
        pop();
    }
}

template <typename T>
int FMIQueue<T>::size()
{
    int res = 0;
    Node* it = first;
    while (it)
    {
        ++res;
        it = it->next;
    }

    return res;
}

template <typename T>
void FMIQueue<T>::pop()
{
    assert(first != nullptr);

    Node* tmp = first;
    first = first->next;
    delete tmp;

    if (first == nullptr)
    {
        last = nullptr;
    }
}

template <typename T>
void FMIQueue<T>::push_back(const T& data)
{
    Node* elem = new Node();
    elem->data = data;
    elem->next = nullptr;

    if (first == nullptr)
    {
        first = elem;
        last = elem;
        return;
    }
    
    Node* it = first;
    while (it != nullptr)
    {
        if (ord(data, it->data))
        {
            break;
        }

        it = it->next;
    }

    // 1. it == nullptr
    if (it == nullptr)
    {
        // 3 2
        // 2-> next = 1
        // Node(2) = Node(1)
        last->next = elem;
        last = elem;
    }
    // 2. it != nullptr
    else
    {
        // first -> next -> next ... -> elem -> it -> next -> ... -> last
        // elem->data has bigger priority than it->data
        elem->next = it->next;
        it->next = elem;
        std::swap(elem->data, it->data);

        if (!elem->next)
        {
            last = elem;
        }
    }
}

#endif // FMI_QUEUE_H_