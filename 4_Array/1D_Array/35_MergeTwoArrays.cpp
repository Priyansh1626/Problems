#include <iostream>
#include <vector>
using namespace std;

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeTwoArrays(int *arr1, int *arr2, int n, int m)
{
}

int main()
{
    int arr1[] = {0, 0, 1, 2, 3};
    int n = sizeof(arr1) / sizeof(int);
    int arr2[] = {4, 8, 9};
    int m = sizeof(arr2) / sizeof(int);

    printArr(arr1, n);
    printArr(arr2, m);

    mergeTwoArrays(arr1, arr2, n, m);

    return 0;
}