// Print like spiral

#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[][3], int n, int m)
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

vector<int> spiralPrint(int arr[][3], int n, int m)
{
    vector<int> ans;
    int count = 0;
    int total = n * m;

    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n - 1;
    int endingCol = m - 1;

    while (count < total)
    {
        // printing starting row
        for (int i = startingCol; count < total && i <= endingCol; i++)
        {
            ans.push_back(arr[startingRow][i]);
            count++;
        }
        startingRow++;
        // printing last column
        for (int i = startingRow; count < total && i <= endingRow; i++)
        {
            ans.push_back(arr[i][endingCol]);
            count++;
        }
        endingCol--;
        // printing last row
        for (int i = endingCol; count < total && i >= startingCol; i--)
        {
            ans.push_back(arr[endingRow][i]);
            count++;
        }
        endingRow--;
        // printing first column
        for (int i = endingRow; count < total && i >= startingRow; i--)
        {
            ans.push_back(arr[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main()
{
    int arr[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printArr(arr, 3, 3);

    cout << "Spiral print of this array is :- " << endl;
    vector<int> v = spiralPrint(arr, 3, 3);
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}