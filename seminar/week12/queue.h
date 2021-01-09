#ifndef FMI_QUEUE_H_
#define FMI_QUEUE_H_
#include <cassert>

template <typename T>
class FMIQueue
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node* first;
    Node* last;

    void copy(const FMIQueue<T>& other);
    void clear();

public:
    FMIQueue() : first(nullptr), last(nullptr) {}
    FMIQueue(const FMIQueue<T>& other) : first(nullptr), last(nullptr) { copy(other); }
    FMIQueue<T>& operator=(const FMIQueue<T>& other);
    ~FMIQueue() { clear(); }

    T& peek(); // връща данните на първия елемент
    void push_back(const T&); // добавя елемент към края на опашката
    bool pop(); // премахва първия елемент

    bool empty() { return first == nullptr; }
};

template <typename T>
void FMIQueue<T>::copy(const FMIQueue<T>& other)
{
    for (Node* it = other.first; it != nullptr; it = it->next)
    {
        push_back(it->data);
    }
}

template <typename T>
void FMIQueue<T>::clear()
{
    while (pop()) {}
}

template <typename T>
FMIQueue<T>& FMIQueue<T>::operator=(const FMIQueue<T>& other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <typename T>
T& FMIQueue<T>::peek()
{
    assert(!empty());
    return first->data;
}

template <typename T>
void FMIQueue<T>::push_back(const T& data)
{
    Node* tmp = new Node{data, nullptr};
    if (empty())
    {
        first = tmp;
    }
    else
    {
        last->next = tmp;
    }
    last = tmp;
}

template <typename T>
bool FMIQueue<T>::pop()
{
    if (empty())
    {
        return false;
    }

    Node* tmp = first;
    first = first->next;
    delete tmp;

    if (empty())
    {
        last = nullptr;
    }

    return true;
}

#endif // FMI_QUEUE_H_