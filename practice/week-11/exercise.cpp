#include <iostream>
#include <vector>


void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}

void bubbleSort(int arr[], int n)   // O(n^2)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 1; j < n - i - 1; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swapped = true;
                std::swap(arr[j - 1], arr[j]);
            }
        }
        if (!swapped)
        {
            return;
        }
    }
}

void selectionSort(int arr[], int n)    // O(n^2)
{
    for (int i = 0; i < n; i++)
    {
        int max_index = 0;
        for (int j = 1; j < n - i; j++)
        {
            if (arr[max_index] < arr[j])
            {
                max_index = j;
            }
        }
        std::swap(arr[n - i - 1], arr[max_index]);
    }
}

void insertionSort(int arr[], int n)    // O(n^2)
{
    for (int i = 1; i < n; i++)
    {
        int curr_i = i;
        while (curr_i > 0 && arr[curr_i - 1] > arr[curr_i])
        {
            std::swap(arr[curr_i - 1], arr[curr_i]);
            curr_i--;
        }
    }
}

void mergeSorted(int arr[], int start1, int end1, int start2, int end2)
{
    std::vector<int> help;

    int index1 = start1;
    int index2 = start2;
    while (index1 <= end1 && index2 <= end2)
    {
        if (arr[index1] < arr[index2])
        {
            help.push_back(arr[index1]);
            index1++;
        }
        else
        {
            help.push_back(arr[index2]);
            index2++;
        }
    }
    while (index1 <= end1)
    {
        help.push_back(arr[index1]);
        index1++;
    }
    while (index2 <= end2)
    {
        help.push_back(arr[index2]);
        index2++;
    }
    
    for (int i = start1; i <= end2; i++)
    {
        arr[i] = help[i - start1];
    }
}

void mergeSort(int arr[], int start, int end)
{
    std::cout << start << " " << end << std::endl;
    if (end - start < 1)
    {
        return;
    }

    int middle = (end - start) / 2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle + 1, end);

    mergeSorted(arr, start, middle, middle + 1, end);
    // printArray(arr, 8);
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (true)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (pivot < arr[j])
        {
            j--;
        }
        if (i >= j)
        {
            return j;
        }
        std::swap(arr[i], arr[j]);
    }
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = partition(arr, start, end);
        quickSort(arr, start, middle);
        quickSort(arr, middle + 1, end);
    }
}

int main()
{
    int n = 8;
    int arr[] = { 4, 1 ,-1, 10, 7, 123, -11, 3 };
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    // mergeSort(arr, 0, n - 1);
    // quickSort(arr, 0, 7);
    printArray(arr, n);

    return 0;
}

/*
    4 1 -1 4 2 7

    1 -1 4 2 4 7
    .
    .
    .
    n times
    O(n^2)
    ==========
    4 1 -1 4 2 7
    1 4 -1 4 ....
    -1 1 4 4 2 7 -> -1 1 4 2 4 7
    -1 1 2 4 4 7

    O(n.log n)
      v         v
    1 2 8 ||| 1 5 7

    v        v
    4 1 -1 4 2 7
           v|
    2 1 -1 4| 4 7

    v    v  
    2 1 -1 4    4 7
         v|
    -1 1 2| 4

    -1 1 2 4 4 7 -> [1 2 4 4 7] + []
    O(n.log)
    O(n^m)

    4 1 1 4 2 7

    count[10 000] = { 0 };
    for(...)
        count[arr[i]]++ // for i=0 -> count[4]++;

    for (index in count[])
    {
        while (count[index] != 0)
            arr[j] = index;
            count[index]--;
            j++;
    }
    
*/