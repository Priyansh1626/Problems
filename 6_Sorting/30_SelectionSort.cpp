// Selection sort

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

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIndex] > arr[j])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 7, 8, 3, 57, 46, 433, 0};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "After sorting" << endl;
    printArray(arr, n);
    return 0;
}