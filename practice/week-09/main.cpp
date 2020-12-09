#include "trees/bintree.cpp"
#include <iostream>

int main() {
    BinTree<int> t;
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

    std::vector<int> tree = { 1, 2, 3, -1, 5, -1 ,7 };
    BinTree<int> t2;
    t2.formArray(tree);
    t2.bfs();

    return 0;
}

/*
            1
           / \
          2   -1 // nullptr
         / \   \
        4   5   -1


    std::set
    std::map // О(log n)
    std::vector // 2 

    0 * 2 + 1, 0 * 2 + 2,
    i = 1 , 1 * 2 + 1, 1 * 2 + 2
    i = 2 , 2 * 2 + 1, 2 * 2 + 2 
    i = 3 , 3 * 2 + 1
    1 2 -1 4 5 -1 -1 _ _
*/
