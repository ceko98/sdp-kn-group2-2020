#include <iostream>
#include "fmi_list.cpp"
using namespace std;

int main()
{
    FMILinkedList<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    cout << myList[2] << endl;
    
    cout << FMILinkedList<int>(myList)[2] << endl;

    return 0;
}