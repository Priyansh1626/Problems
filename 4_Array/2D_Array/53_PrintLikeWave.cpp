// Print like wave
// Given array of size(n*m), print the array in a sine wave.
// Print the first column top to bottom , next column bottom to top and so on

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

vector<int> printWave(int arr[][3], int n, int m)
{
    vector<int> ans;
    for (int j = 0; j < m; j++)
    {
        if (j & 1) // odd indexes
        {
            for (int i = n - 1; i >= 0; i--)
            {
                // cout << arr[i][j] << " ";
                ans.push_back(arr[i][j]);
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                // cout << arr[i][j] << " ";
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
}

int main()
{
    int arr[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printArr(arr, 3, 3);
    vector<int> ans = printWave(arr, 3, 3);
    cout << "Wave array" << endl;
    for (int v : ans)
    {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}