#ifndef FMI_LINKED_LIST_H_
#define FMI_LINKED_LIST_H_

#include <stdexcept>

template <typename T>
class FMILinkedList
{
    struct Node
    {
        T data;
        Node *next;
    };

private:
    Node *first, *last;
    int size;

    void copy(const FMILinkedList &other); // DONE
    void clear(); // DONE

    Node *find(int index);

public:
    FMILinkedList(); // DONE
    FMILinkedList(const FMILinkedList<T> &other); // DONE
    FMILinkedList &operator=(const FMILinkedList<T> &other); // DONE
    ~FMILinkedList(); // DONE

    void push_back(const T& data);
    void erase_at(int index);
    int getSize();

    T &operator[](int index);
};

template <typename T>
FMILinkedList<T>::FMILinkedList() : first(nullptr), last(nullptr), size(0) {}

template <typename T>
void FMILinkedList<T>::clear()
{
    Node *iter = first, *temp;
    while (iter != nullptr)
    {
        temp = iter;
        iter = iter->next;
        delete temp;
    }
    first = nullptr;
    last = nullptr;
    size = 0;
}

template <typename T>
FMILinkedList<T>::~FMILinkedList()
{
    clear();
}

template <typename T>
void FMILinkedList<T>::copy(const FMILinkedList &other)
{
    Node *iter = other.first;
    first = nullptr;
    last = nullptr;

    while (iter != nullptr)
    {
        push_back(iter->data);
    }
}

template <typename T>
FMILinkedList<T>::FMILinkedList(const FMILinkedList<T> &other) : first(nullptr)
{
    copy(other);
}

template <typename T>
FMILinkedList<T> &FMILinkedList<T>::operator=(const FMILinkedList<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}


template <typename T>
void FMILinkedList<T>::push_back(const T& data)
{
    auto cell = new Node();
    cell->data = data;
    cell->next = nullptr;
    ++size;

    if (first == nullptr)
    {
        first = cell;
        last = first;
        return;
    }

    last->next = cell;
    last = cell;
}

template <typename T>
void FMILinkedList<T>::erase_at(int index)
{
    Node *temp = first;

    if (index < 0 || index > size - 1)
    {
        return;
    }

    --size;

    if (index == 0)
    {
        first = first->next;
        delete temp;
        if (first == nullptr)
        {
            last = nullptr;
        }
        return;
    }

    temp = find(index - 1);

    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    if (toDelete == last)
    {
        last = temp;
    }
    delete toDelete;
}

template <typename T>
int FMILinkedList<T>::getSize()
{
    return size;
}

template <typename T>
T &FMILinkedList<T>::operator[](int index)
{
    return find(index)->data;
}

template <typename T>
typename FMILinkedList<T>::Node *FMILinkedList<T>::find(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::runtime_error("Index out of bounds");
    }

    int currentIndex = 0;
    Node *iterator = first;
    while (currentIndex != index)
    {
        iterator = iterator->next;
        currentIndex++;
    }

    return iterator;
}

#endif // FMI_LINKED_LIST_H_

