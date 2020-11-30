#include <iostream>
#include "tree.h"

int main()
{
    FMIBinTree<int> intTree;
    intTree.push(4);
    intTree.push(5);
    intTree.push(2);
    intTree.push(1);
    intTree.push(3);

    auto printData = [&](const int& nodeData) {
        std::cout << nodeData << " ";
    };

    intTree.executeInDepth(printData);
    std::cout << "\n";

    intTree.erase(4);

    intTree.executeInDepth(printData);
    std::cout << "\n";
}
