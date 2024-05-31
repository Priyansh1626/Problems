// Peak Index in a Mountain array

#include <iostream>
using namespace std;

int indexOfPeak(int arr[], int n)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    int arr[] = {0, 6, 10, 50, 4, 2, 1};
    int size = sizeof(arr) / sizeof(int);
    int top = indexOfPeak(arr, size);
    cout << "Peak of this mountain array is " << top << endl;
    return 0;
}