// Find index of Pivot element in a sorted and rotated array

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

int main()
{
    int arr[] = {7, 9, 1, 2, 3};
    int size = sizeof(arr) / sizeof(int);
    int pivot = findPivot(arr, size);
    cout << "Pivot element is at index " << pivot << endl;
    return 0;
}
