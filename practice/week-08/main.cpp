#include "trees/bintree.cpp"
#include <iostream>

int main() {
    // BinTree<int> t;
    // t.insertOrdered(5);
    // t.insertOrdered(2);
    // t.insertOrdered(3);
    // t.insertOrdered(1);
    // t.insertOrdered(9);
    // t.insertOrdered(8);
    // t.insertOrdered(0);
    

    // t.printSorted();

    // std::cout << std::endl;
    // std::cout << t.findDepth(3) << std::endl;
    // t.insertOrdered(10);
    // t.insertOrdered(7);
    // t.insertOrdered(8);
    // t.insertOrdered(4);
    // t.insertOrdered(6);
    // t.insertOrdered(5);
    // t.insertOrdered(1);

    // t.insertOrdered(4);
    // t.insertOrdered(3);
    // t.insertOrdered(2);
    // t.insertOrdered(1);

    // t.bfs();
    // std::cout << std::endl;

    // t.deleteElem(4);
    // t.bfs();
    // std::cout << std::endl;

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