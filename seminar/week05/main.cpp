#include <iostream>
#include "queue.h"

// array, list, stack ... queue
// array - последователно представяне, произв. достъп, фикс. капацитет
// list - ??? представяне, последователен достъп, нефикс. капацитет
//  - свързан списък: свързано представяне!
// stack - ??? представяне, достъп само до последния елемент, нефикс. капацитет (LIFO)
// 
// queue - ??? представяне, достъп само до първия елемент, нефикс. капацитет (FIFO)
int main()
{
    FMIQueue<int> intQueue;
    intQueue.push_back(1);
    intQueue.push_back(2);
    intQueue.push_back(3);
    intQueue.push_back(4);
    intQueue.push_back(5);

    while (!intQueue.empty())
    {
        std::cout << intQueue.peek() << " ";
        intQueue.pop();
    }

    std::cout << "\n";
    return 0;
}