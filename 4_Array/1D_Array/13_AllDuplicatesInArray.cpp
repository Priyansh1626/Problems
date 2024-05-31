// Given an integer array nums of length n where all the integers of nums are in the range [1,n] and each integer appears once or twice, returns an array of all the integers that appears twice.
// You must write an algo that runs in O(n) time and uses only constant extra space.

//                          HW problem

// [1,1,2,3,4,3,4,5,6];

// -> [1,3,4]

#include <iostream>
using namespace std;

void func(int *arr, int n)
{
    int newarr[10];
    int count = 0;
    int j = 0, i = 0;

    while (i < n - 1)
    {
        if (arr[i] == arr[i + 1])
        {
            newarr[j] = arr[i];
            i = i + 2;
            j++;
            count++;
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << newarr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 2, 3, 3, 4}; // sorted array
    int size = sizeof(arr) / sizeof(int);
    func(arr, size);
    return 0;
}