#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "bintree.h"
#include <cassert>
#include <limits>
#include <queue>

template <class T>
BinTree<T>::BinTree() : root(nullptr)
{
}

template <class T>
void BinTree<T>::add(const T &x, const char *trace)
{
    if (root == nullptr)
    {
        assert(trace[0] == 0);
        root = new node{x, nullptr, nullptr};
        return;
    }

    assert(trace[0] != 0);

    BinTree<T>::node *current = root;

    while (trace[1] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        assert(current != nullptr);
        ++trace;
    }

    if (trace[0] == 'L')
    {
        assert(current->left == nullptr);
        current->left = new node{x, nullptr, nullptr};
    }
    else if (trace[0] == 'R')
    {
        assert(current->right == nullptr);
        current->right = new node{x, nullptr, nullptr};
    }
    else
    {
        assert(false);
    }
}

template <class T>
T BinTree<T>::get(const char *trace) const
{

    BinTree<T>::node *element = locate(trace);
    assert(element != nullptr);
    return element->data;
}

template <class T>
typename BinTree<T>::node *BinTree<T>::locate(const char *trace) const
{
    BinTree<T>::node *current = root;
    while (trace[0] != 0)
    {
        assert(current != nullptr);
        assert(trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        ++trace;
    }

    assert(current != nullptr);
    return current;
}

template <class T>
T &BinTree<T>::operator[](const char *trace)
{
    BinTree<T>::node *element = locate(trace);
    assert(element != nullptr);
    return element->data;
}

template <class T>
void BinTree<T>::toDotty(std::ostream &out)
{
    out << "digraph G{\n";
    toDottyHelp(out, root);
    out << "}";
}

template <class T>
void BinTree<T>::insertOrdered(T elem)
{
    if (root == nullptr)
    {
        node *first = new node(elem);
        root = first;
        return;
    }

    insertOrderedHelp(root, elem);
}

template <class T>
void BinTree<T>::insertOrderedHelp(node *curr, T elem)
{
    if (curr->data < elem)
    {
        if (curr->right == nullptr)
        {
            curr->right = new node(elem);
        }
        else
        {
            insertOrderedHelp(curr->right, elem);
        }
    }
    else
    {
        if (curr->left == nullptr)
        {
            curr->left = new node(elem);
        }
        else
        {
            insertOrderedHelp(curr->left, elem);
        }
    }
}

template <class T>
void BinTree<T>::printSorted()
{
    printSortedHelp(root);
}

template <class T>
void BinTree<T>::printSortedHelp(node *curr)
{
    if (curr == nullptr)
    {
        return;
    }

    printSortedHelp(curr->left);
    std::cout << curr->data << " ";
    printSortedHelp(curr->right);
}

template <class T>
int BinTree<T>::findDepth(T elem)
{
    return findDepthHelp(root, elem);
}

template <class T>
int BinTree<T>::findDepthHelp(node *curr, T elem)
{
    if (curr->data == elem)
    {
        return 0;
    }

    if (elem <= curr->data)
    {
        return 1 + findDepthHelp(curr->left, elem);
    }
    else
    {
        return 1 + findDepthHelp(curr->right, elem);
    }
}

template <class T>
void BinTree<T>::bfs()
{
    std::queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *curr = q.front();
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
        std::cout << curr->data << " ";
        q.pop();
    }
}

template<>
BinTree<int>::node * BinTree<int>::formArrayHelp(std::vector<int> arr, int rootIndex)
{
    if (rootIndex >= arr.size() || arr[rootIndex] == -1) {
        return nullptr;
    }

    node * curr = new node(arr[rootIndex]);
    
    node * left = nullptr;
    node * right = nullptr;

    if (rootIndex * 2 + 1 < arr.size()) {
        left = formArrayHelp(arr, rootIndex * 2 + 1);
    }
    if (rootIndex * 2 + 2 < arr.size()) {
        right = formArrayHelp(arr, rootIndex * 2 + 2);
    }

    curr->left = left;
    curr->right = right;

    return curr;
}

template<>
void BinTree<int>::formArray(std::vector<int> arr)
{
    node * root = formArrayHelp(arr, 0);
    this->root = root;
}

#endif