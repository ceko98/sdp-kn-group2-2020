#include "trees/bintree.cpp"
#include <iostream>

int main() {
    BinTree<char> t;
    t.add('c', "");
    t.add('a', "L");
    t.add('a', "R");
    t.add('c', "LL");
    t.add('a', "RL");
    t.add('c', "RR");

    t.printWordsDFS();

    return 0;
}

/*

*/
