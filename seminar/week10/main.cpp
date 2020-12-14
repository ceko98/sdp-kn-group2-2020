#include <iostream>
#include <vector>
#include "queue.cpp"

int main()
{
    FMIQueue<int> intQueue([](const int& left, const int& right) { return left < right; });
    intQueue.push_back(2);
    intQueue.push_back(3);
    intQueue.push_back(1);
    intQueue.push_back(5);
    intQueue.push_back(4);

    while (!intQueue.empty())
    {
        std::cout << intQueue.front() << " ";
        intQueue.pop();
    }
    std::cout << "\n";

    // example for ordering of other types
    FMIQueue<std::vector<int>> vectorQueue(
        [](const std::vector<int>& left, const std::vector<int>& right)
        {
            return left.size() < right.size();
        });
    return 0;
}