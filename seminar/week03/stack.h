#ifndef FMI_STACK_H_
#define FMI_STACK_H_

#include <stdexcept>

// DS that gives us access to the last included element only
template <typename T>
class FMIStack
{
private:
    struct Node
    {
        T data;
        Node* next;
    };

    Node* top;
    
public:
    FMIStack();
    FMIStack(const FMIStack<T>&) = delete;
    FMIStack& operator=(const FMIStack<T>&) = delete;
    ~FMIStack();

    T& peek(); // gives us the top element of the stack
    bool pop(); // removes the top element of the stack
    void push(const T&); // add element to the stack

    bool empty() { return !top; }
};

template <typename T>
FMIStack<T>::FMIStack() : top(nullptr)
{}

template <typename T>
FMIStack<T>::~FMIStack()
{
    while (!empty())
    {
        pop();
    }
}

template <typename T>
bool FMIStack<T>::pop()
{
    if (empty())
    {
        return false;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
    return true;
}

template <typename T>
T& FMIStack<T>::peek()
{
    if (empty())
    {
        throw std::runtime_error("Cannot peek at empty stack!");
    }

    return top->data;
}

template <typename T>
void FMIStack<T>::push(const T& data)
{
    Node* tmp = new Node();
    tmp->data = data;
    tmp->next = top;
    top = tmp;
}

#endif // FMI_STACK_H_
