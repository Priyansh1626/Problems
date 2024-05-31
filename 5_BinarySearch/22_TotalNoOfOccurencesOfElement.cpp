// Find total number of occurrences of an element in an array

#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int element)
{
    int s = 0, e = n - 1;
    int mid = (s + (e - s) / 2);
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == element)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > element)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOccurence(int arr[], int n, int element)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == element)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > element)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    int element;
    cout << "Enter an element" << endl;
    cin >> element;

    int first = firstOccurence(arr, size, element);
    int last = lastOccurence(arr, size, element);

    if (first == -1 && last == -1)
    {
        cout << element << " is not present in this array" << endl;
    }
    else
    {
        int ans = (last - first) + 1;

        cout << "There are total " << ans << " occurences of " << element << " in this array" << endl;
    }

    return 0;
}