#include <iostream>
#include "hashset.h"
using namespace std;

int main()
{
    HashSet<int> intHashSet([](const int& data) { return data; });
    std::cout << intHashSet.emplace(3) << "\n";
    std::cout << intHashSet.emplace(5) << "\n";
    std::cout << intHashSet.emplace(100) << "\n";

    std::cout << intHashSet.getSize() << "\n";
    std::cout << intHashSet.remove(50) << "\n";
    std::cout << intHashSet.remove(3) << "\n";
    std::cout << intHashSet.emplace(5) << "\n";

    // std::unordered_set
    // std::unordered_map
    return 0;
}