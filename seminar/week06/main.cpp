#include <iostream>
#include <stack>

/**
 * Зад 4. Дадени са 3 стека. Във всеки от стековете цилиндри наредени един върху друг представени
 * чрез число отговарящо на височината на всеки цилиндър. Да се направи метод който приема 
 * 3 стека за аргументи и показва максималната височина за която и 3те стека са равни. 
 * Резултата трябва да се получи след последнователно изваждане на елементи от стековете.
 * Note: стек с височина 0 пак е стек.
 */

/**
 *      one           two             three
 * 21   4       24    7         18    4
 * 17   6       17    6         14    3
 * 11   2       11    4         11    8
 * 9    1       7     3         3     2
 * 8    8       4     4         1     1
 */

using Tower = std::stack<int>;

void reverseStack(Tower original, Tower& copy)
{
    while (!original.empty()) {
        copy.push(original.top());
        original.pop();
    }
}

int findMaxHight(Tower one, Tower two, Tower three)
{
    // 1.1: reverse stacks
    Tower oneClone, twoClone, threeClone;
    reverseStack(one, oneClone);
    reverseStack(two, twoClone);
    reverseStack(three, threeClone);

    // 1.2: initialize stack heights with 0
    int oneHeight = 0, twoHeight = 0, threeHeight = 0;

    // all stacks can have height 0
    int maxHeight = 0;

    // 1.3: get smallest non-empty stack -> add one element to it
    while (!oneClone.empty() || !twoClone.empty() || !threeClone.empty())
    {
        Tower* smallest = nullptr;
        int* smallestHeight = nullptr;
        if (oneHeight <= twoHeight && oneHeight <= threeHeight)
        {
            smallest = &oneClone;
            smallestHeight = &oneHeight;
        }
        else if (twoHeight <= threeHeight)
        {
            smallest = &twoClone;
            smallestHeight = &twoHeight;
        }
        else
        {
            smallest = &threeClone;
            smallestHeight = &threeHeight;
        }

        if (smallest->empty())
        {
            break;
        }

        *smallestHeight += smallest->top();
        smallest->pop();

        //  - check if stacks are equal height
        //      IF TRUE => save current stack height as maximum
        if (oneHeight == twoHeight && twoHeight == threeHeight)
        {
            maxHeight = oneHeight;
        }
    }

    // return maximum stack height;
    return maxHeight;
}

int findHeight(Tower target)
{
    int currHeight = 0;
    while (!target.empty())
    {
        currHeight += target.top();
        target.pop();
    }

    return currHeight;
}

// Solution 2: find height and subtract elements from largest
int findMaxHeight2(Tower one, Tower two, Tower three)
{
    int oneHeight = findHeight(one);
    int twoHeight = findHeight(two);
    int threeHeight = findHeight(three);

    while (!one.empty() || !two.empty() || !three.empty())
    {
        if (oneHeight == twoHeight && twoHeight == threeHeight)
        {
            return oneHeight;
        }
        
        Tower* largest = nullptr;
        int* largestHeight = nullptr;
        if (oneHeight >= twoHeight && twoHeight >= threeHeight)
        {
            largest = &one;
            largestHeight = &oneHeight;
        }
        else if (twoHeight >= threeHeight)
        {
            largest = &two;
            largestHeight = &twoHeight;
        }
        else
        {
            largest = &three;
            largestHeight = &threeHeight;
        }

        if (largest->empty()) {
            break;
        }

        *largestHeight -= largest->top();
        largest->pop();
    }

    return 0;
}

int main()
{
    Tower one, two, three;
    // one.push(8);
    // one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);
    one.push(1);

    // two.push(4);
    // two.push(3);
    two.push(3);
    two.push(4);

    // three.push(1);
    // three.push(2);
    three.push(1);
    three.push(2);
    three.push(4);
    three.push(3);

    std::cout << findMaxHeight2(one, two, three) << std::endl;
}
