// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise

#include <iostream>
using namespace std;

int isUnique(int *arr, int n)
{
    int count = 1;
    int occ[100];
    int flag = 1;
    int a = 0;
    for (int i = 0; i < n; i += count)
    {
        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        occ[a] = count;
        a++;
    }
    for (int i = 0; i < a - 1; i++)
    {
        for (int j = i + 1; j < a; j++)
        {
            if (occ[i] == occ[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
    return flag;
}

int main()
{
    int arr[] = {1, 1, 3, 3, 3, 5, 5, 5, 5}; // sorted array
    int size = sizeof(arr) / sizeof(int);
    int flag = isUnique(arr, size);
    if (flag)
        cout << "true";
    else
        cout << "false";

    return 0;
}
