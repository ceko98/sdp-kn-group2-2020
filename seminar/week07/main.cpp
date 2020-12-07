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

/**
 *   Пример за задача за двоично дърво:
 *   Даденото двоично дърво описва аритметичен израз.
 *   Да се оцени дадения израз
 * 
 *          -
 *      /      \
 *     +        * 
 *    / \      / \
 *   5   *    7   3
 *     /   \
 *    8     :
 *         / \
 *        2   4
 * 
 * 
 *   (5 + 8 * 2 : 4) - (7 * 3) => A - B
 *   A = (5) + (8 * 2 : 4) => 5 + C
 *   B = (7) * (3)
 *   C = (8) * (2 : 4) => 8 * D
 *   D = (2) : (4)
 * 
 * 
 * Node* node
 * float evaluate(); => връща резултата от оценяването на дадено поддърво
 * float NumberNode::evaluate() { return content; }
 * float OperationNode::evaluate()
 * {
 *      float op1 = evaluate(this->left);
 *      float op2 = evaluate(this->right);
 *      std::function<float(float, float)> functor = getFunctor(this->operatorSign);
 *      return functor(op1, op2);
 * }
 */

