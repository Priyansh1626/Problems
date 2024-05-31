// Find the pairs of two numbers whose sum is equal to the given number from an array.

#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6}; // sorted array
    int size = sizeof(arr) / sizeof(int);
    int element;
    cout << "Enter element" << endl;
    cin >> element;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == element)
            {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}