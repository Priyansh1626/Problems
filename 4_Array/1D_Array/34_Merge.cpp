// Merge two sorted Arrays and the resultent array must be sorted

#include <iostream>
// #include <vector>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr1[], int n, int arr2[], int m, int arr3[])
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    while (i < n)
    {
        arr3[k] = arr1[i];
        k++;
        i++;
    }
    while (j < m)
    {
        arr3[k] = arr2[j];
        k++;
        j++;
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7, 9, 11};
    int size1 = sizeof(arr1) / sizeof(int);
    // cout << size1 << endl;
    // printArray(arr1, size1);

    int arr2[] = {2, 4, 6, 8};
    int size2 = sizeof(arr2) / sizeof(int);
    // cout << size2 << endl;
    // printArray(arr2, size2);

    int size3 = size1 + size2;
    int arr3[size3];
    // cout << size3 << endl;
    // printArray(arr3, size3);

    merge(arr1, size1, arr2, size2, arr3);
    printArray(arr3, size3);

    return 0;
}