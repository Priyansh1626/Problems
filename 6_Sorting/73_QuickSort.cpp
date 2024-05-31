#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;

    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }

    // placing pivot at its right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // balancing partition
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int s, int e)
{
    if (s >= e)
        return;
    // partition
    int p = partition(arr, s, e);

    // left part sorting
    quickSort(arr, s, p - 1);

    // right part sorting
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {1, 2, 4, 1, 2, 6, 3, 78, 4, 6, 676};
    int size = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    return 0;
}