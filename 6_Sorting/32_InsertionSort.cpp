// Insertion Sort

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

// int partition(int *arr, int s, int e)
// {
//     int pivot = arr[s];

//     int cnt = 0;

//     for (int i = s + 1; i <= e; i++)
//     {
//         if (arr[i] <= pivot)
//         {
//             cnt++;
//         }
//     }

//     // placing pivot at its right position
//     int pivotIndex = s + cnt;
//     swap(arr[pivotIndex], arr[s]);

//     // balancing partition
//     int i = s, j = e;
//     while (i < pivotIndex && j > pivotIndex)
//     {
//         while (arr[i] <= pivot)
//         {
//             i++;
//         }
//         while (arr[j] > pivot)
//         {
//             j--;
//         }
//         if (i < pivotIndex && j > pivotIndex)
//         {
//             swap(arr[i++], arr[j--]);
//         }
//     }
//     return pivotIndex;
// }

// void quickSort(int *arr, int s, int e)
// {
//     if (s >= e)
//         return;
//     // partition
//     int p = partition(arr, s, e);

//     // left part sorting
//     quickSort(arr, s, p - 1);

//     // right part sorting
//     quickSort(arr, p + 1, e);
// }

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int a[] = {44, 45, 46, 77, 1, 2, 3, 4};
    int n = sizeof(a) / sizeof(int);

    printArray(a, n);
    insertionSort(a, n);
    // quickSort(a, 0, n - 1);
    cout << "After sorting" << endl;
    printArray(a, n);

    return 0;
}