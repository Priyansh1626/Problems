// Search an element in a 2D array

#include <iostream>
using namespace std;

bool search(int arr[][3], int element, int n, int m)
{
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (arr[row][col] == element)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int arr[3][3];
    int element;
    cout << "Enter the array" << endl;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cin >> arr[row][col];
        }
    }
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << "Enter the element : ";
    cin >> element;
    cout << "Is element " << element << " is present : " << search(arr, element, 3, 3);

    return 0;
}