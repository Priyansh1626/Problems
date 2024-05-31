// Search in a matrix 2
// (1) Integers in each row are sorted in ascending from left to right
// (2) Integers in each column are sorted in ascending from top to bottom

#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[][5], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool searchMatrix(int arr[][5], int n, int m, int key)
{
    int rowIndex = 0;
    int colIndex = m - 1;

    while (rowIndex < n && colIndex >= 0)
    {
        int element = arr[rowIndex][colIndex];
        if (element == key)
        {
            return true;
        }
        if (element < key)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return false;
}

int main()
{
    int arr[][5] = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    printArr(arr, 5, 5);
    int element;
    cout << "Enter the element " << endl;
    cin >> element;

    if (searchMatrix(arr, 5, 5, element))
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}