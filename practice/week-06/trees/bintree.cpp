#ifndef __BINTREE_CPP
#define __BINTREE_CPP

#include "bintree.h"
#include <cassert>
#include <limits> 

template <class T>
BinTree<T>::BinTree():root(nullptr)
{

}

template <class T>
void BinTree<T>::add (const T &x, const char *trace)  
{
    if (root == nullptr)
    {
        assert (trace[0] == 0);
        root = new node {x,nullptr,nullptr};
        return;
    }

    assert (trace[0] != 0);

    BinTree<T>::node *current = root;

    while (trace[1] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');
        
        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }

        assert (current != nullptr);    
        ++trace;
    }

    if (trace[0] == 'L')
    {
        assert(current->left == nullptr);
        current->left = new node {x,nullptr,nullptr};
    } else if (trace[0] == 'R')
    {
        assert(current->right == nullptr);
        current->right = new node {x,nullptr,nullptr};
    } else 
    {
        assert (false);
    }



}

template <class T>
T BinTree<T>::get (const char *trace) const
{

    BinTree<T>::node *element = locate(trace);
    assert (element != nullptr);
    return element->data;

}

template <class T>
typename BinTree<T>::node* BinTree<T>::locate (const char *trace) const
{
    BinTree<T>::node *current = root;
    while (trace[0] != 0)
    {
        assert (current != nullptr);
        assert (trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        } else 
        {
            current = current->right;
        }

        ++trace;
    }

    assert (current != nullptr);
    return current;
}

template <class T>
T& BinTree<T>::operator [](const char *trace)
{
    BinTree<T>::node *element = locate(trace);
    assert (element != nullptr);
    return element->data; 
}

template <class T>
void BinTree<T>::toDotty(std::ostream& out)
{
    out << "digraph G{\n";
    toDottyHelp(out, root);
    out << "}";
}

template<class T>
T BinTree<T>::min() {
    return this->minHelper(this->root);
}

template<>
int BinTree<int>::minHelper(node * node) {
    if (node == nullptr) {
        return std::numeric_limits<int>::max();
    }

    int leftMin = this->minHelper(node->left);
    int rightMin = this->minHelper(node->right);
    int lefRightMin = std::min(leftMin, rightMin);

    return std::min(node->data, lefRightMin);
}

template<class T>
bool BinTree<T>::isEven() {
    return this->isEvenHelper(this->root);
}
template<class T>
bool BinTree<T>::isEvenHelper(node * node) {
    if (node == nullptr) {
        return true;
    }
    // true && x = x
    return node->data % 2 == 0
        && isEvenHelper(node->left)
        && isEvenHelper(node->right);
}

template<class T>
bool BinTree<T>::hasWord(const char * str) {
    return this->hasWordHelper(this->root, str);
}

template<class T>
bool BinTree<T>::hasWordHelper(node * node, const char * str) {
    if (node == nullptr) {
        return false;
    }

    bool isCurrentMatch = false;
    if (str[0] == node->data) {
        isCurrentMatch = this->matchWord(node, str);
    }
    bool hasLeft = this->hasWordHelper(node->left, str);
    bool hasRight = this->hasWordHelper(node->right, str);

    return isCurrentMatch || hasLeft || hasRight;
}

template<class T>
bool BinTree<T>::matchWord(node * node, const char * str) {
    if (node == nullptr) {
        return false;
    }

    if (node->left == nullptr && node->right == nullptr && str[1] == '\0') {
        return str[0] == node->data;
    }

    if (node->data != str[0]) {
        return false;
    }

    bool leftMatch = matchWord(node->left, ++str);
    bool rightMatch = matchWord(node->right, ++str);

    return leftMatch || rightMatch;
}


#endif