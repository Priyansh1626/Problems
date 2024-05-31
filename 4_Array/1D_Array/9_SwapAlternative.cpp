// Swap alternate numbers in an array.

#include <iostream>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlt(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    printArr(arr, n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    swapAlt(arr, size);

    return 0;
}