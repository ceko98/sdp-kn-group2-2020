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

    private:
    struct node
    {
        T data;
        node *left, *right;
    };

    node* locate (const char*) const;
    node *root;
};

#endif