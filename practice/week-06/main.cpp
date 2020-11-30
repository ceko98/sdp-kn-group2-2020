#include "trees/bintree.cpp"
#include <iostream>

int main() {
    BinTree<int> t;
    t.add(1, "");
    t.add(2, "L");
    t.add(7, "R");
    t.add(0, "LL");
    t.add(7, "LR");

    // std::cout << t.min() << std::endl;

    BinTree<char> t2;
    t2.add('a', "");
    t2.add('b', "L");
    t2.add('e', "R");
    t2.add('d', "LL");
    t2.add('c', "LR");

    std::cout << t2.hasWord("ab") << std::endl;

    return 0;
}

/*
              4
	        /   \
           2     7
         /  \     
        0    7 

        [4,2,0,7,7] O(n^2), O(n . logn)
*/


/*      bd
              a
	        /   \
           b     e
         /  \     
        d    c 
*/

/*
    O(n^2)
    [][] [][]   [][][][] |
    [   ][  ]   [  ][  ] |
    [       ]   [      ] |  O(logn)
    [                  ] |
              ^
    (O(n) + O(n)) . O(logn) = O(n.logn)
*/
