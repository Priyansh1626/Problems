// There are 2m+1 elements in an array.m numbers are twice and only 1 number is single. Find that single number.

#include <iostream>
using namespace std;

void uniqueElement(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        // xor cut off the same elemenets
        ans = ans ^ arr[i];
    }
    cout << ans;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 3, 1, 4};
    int size = sizeof(arr) / sizeof(int);
    uniqueElement(arr, size);
    return 0;
}