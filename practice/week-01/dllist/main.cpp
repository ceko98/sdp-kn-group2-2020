#include <iostream>
#include "dllist.h"



int main()
{
    DLList<int> list;

    list += 1;
    list += 2;
    list += 3;

    std::cout << list.length() << " " << std::endl;
    list.insertAt(10, 0);

    std::cout << list << std::endl;
}