// Binary search in a 2D array

#include <iostream>
#include <vector>
using namespace std;

bool search(int arr[][3], int n, int m, int key)
{
    int start = 0;
    int end = (n * m) - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        int element = arr[mid / n][mid % m];
        if (element == key)
        {
            return true;
        }
        if (element < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}

int main()
{
    int arr[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int element;
    cout << "Enter the element " << endl;
    cin >> element;

    if (search(arr, 3, 3, element))
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}