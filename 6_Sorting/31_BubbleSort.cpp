// Bubble Sort

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

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        cout << "Round " << i << endl;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 4, 4};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    bubbleSort(arr, n);
    cout << "After sorting" << endl;
    printArray(arr, n);

    return 0;
}