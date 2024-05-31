// Returns the index of row having the maxSum and also show the sum

#include <iostream>
using namespace std;

int largestRowSum(int arr[][3], int i, int j)
{
    int maxi = INT_MIN;
    int rowIndex = -1;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = i;
        }
    }
    cout << "The maximum sum is : " << maxi << endl;
    return rowIndex;
}

int main()
{
    int arr[3][3];
    int element;
    cout << "Enter the array" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int rowIndex = largestRowSum(arr, 3, 3);
    cout << "Row Index is : " << rowIndex << endl;
    return 0;
}