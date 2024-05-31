// Through recursion apply Linear search

#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int k)
{
    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
        return true;

    if (s > e)
        return false;

    if (arr[mid] < k)
        return binarySearch(arr, mid + 1, e, k);
    else
        return binarySearch(arr, s, mid - 1, k);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int element;
    cout << "Enter the element" << endl;
    cin >> element;
    if (binarySearch(arr, 0, n - 1, element))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}