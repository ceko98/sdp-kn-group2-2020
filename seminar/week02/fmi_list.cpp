#ifndef FMI_LINKED_LIST_H_
#define FMI_LINKED_LIST_H_

template <typename T>
class FMILinkedList
{
    struct Node
    {
        T data;
        Node *next;
    };

private:
    Node *first;
    void copy(const FMILinkedList &other); // DONE
    void clear(); // DONE

public:
    FMILinkedList(); // DONE
    FMILinkedList(const FMILinkedList<T> &other);
    FMILinkedList &operator=(const FMILinkedList<T> &other);
    ~FMILinkedList(); // DONE

    void push_back(const T& data);
    void erase_at(int index);
    int size();
};

template <typename T>
FMILinkedList<T>::FMILinkedList() : first(nullptr) {}

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
}

template <typename T>
FMILinkedList<T>::~FMILinkedList()
{
    clear();
}

template <typename T>
void FMILinkedList<T>::copy(const FMILinkedList &other)
{
    if (other.first == nullptr)
    {
        first = nullptr;
        return;
    }

    Node *thisIter, *otherIter = other.first;
    first = new Node();
    thisIter = first;

    while (otherIter != nullptr)
    {
        thisIter->data = otherIter->data;
        if (otherIter->next != nullptr)
        {
            thisIter->next = new Node();
        }
        thisIter = thisIter->next;
        otherIter = otherIter->next;
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

#endif // FMI_LINKED_LIST_H_