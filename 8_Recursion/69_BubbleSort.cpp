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

void bubbleSort(int *arr, int n)
{
    if (n == 1 || n == 0)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}