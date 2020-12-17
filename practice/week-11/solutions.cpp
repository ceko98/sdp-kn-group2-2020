#include <iostream>
#include "heap-sort.cpp"
#include "quick-sort.cpp"

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

int main()
{
    int arr[] = { 5, 8, 2, 4, 0, 123, 33, -4 };
    // heapSort(arr, 8);
    // quickSort(arr, 0, 7);
    printArray(arr, 8);
    
    return 0;
}