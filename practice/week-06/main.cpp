#include "trees/bintree.cpp"
#include <iostream>

int main() {
    BinTree<int> t;
    t.add(1, "");
    t.add(2, "L");
    t.add(3, "R");
    t.add(4, "LR");
    t.add(5, "LL");

    t.print();

    return 0;
}