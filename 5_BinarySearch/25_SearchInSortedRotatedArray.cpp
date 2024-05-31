// Search an element in a sorted and rotated array

#include <iostream>
using namespace std;

int findPivot(int arr[], int n)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int binarySearch(int *arr, int start, int end, int element)
{
    int s = start, e = end, mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (element == arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}

int search(int arr[], int n, int element)
{
    int pivot = findPivot(arr, n);
    if (element <= arr[n - 1] && element >= arr[pivot])
    {
        return binarySearch(arr, pivot, n - 1, element);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, element);
    }
}

int main()
{
    int arr[] = {7, 9, 1, 2, 3};
    int size = sizeof(arr) / sizeof(int);
    int element;
    cout << "Enter the number you want to search" << endl;
    cin >> element;
    int got = search(arr, size, element);
    if (got)
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}