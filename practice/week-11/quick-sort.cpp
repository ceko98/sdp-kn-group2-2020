#include <algorithm>

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start;
    int j = end;
    for(;;)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
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

void quickSort(int arr[], int start, int end) {
    if (start < end)
    {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot);
        quickSort(arr, pivot + 1, end);
    }
}
