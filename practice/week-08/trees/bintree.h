#ifndef __BINTREE_H
#define __BINTREE_H

#include <iostream>

template <class T>
class BinTree
{
    public:

    BinTree();

    //Вмъква ново листо в дървото на дадена позиция. Не позволява 
    //изменяне на съшествуващи елементи
    void add (const T&, const char*);
    T get (const char*) const;
    T& operator [](const char*);
    void toDotty(std::ostream& out);

    bool member (const T& x);
    T min();
    bool isEven();
    bool hasWord(const char * str);

    void insertOrdered(T elem);
    void printSorted();
    int findDepth(T elem);
    void bfs();
    void deleteElem(T elem);

    private:
    struct node
    {
        T data;
        node *left, *right;

        node(T elem) : data(elem), left(nullptr), right(nullptr) {
        }
    };

    node* locate (const char*) const;
    node *root;
    void insertOrderedHelp(node * curr, T elem);
    void printSortedHelp(node * curr);
    int findDepthHelp(node * vurr, T elem);
    void deleteElemHelp(node *  curr, node * parent, T elem);
    node * findParentOfMin(node *  curr, node *  parent);
    node * findParentOfMax(node *  curr, node *  parent);

};

#endif