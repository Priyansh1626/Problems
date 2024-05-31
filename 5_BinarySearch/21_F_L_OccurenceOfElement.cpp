// Find the First and Last most position of an element in a sorted array

#include <iostream>
using namespace std;

void firstOccurence(int arr[], int n, int element)
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
    cout << ans << " ";
}

void lastOccurence(int arr[], int n, int element)
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
    cout << ans << " " << endl;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 3, 4};
    int size = sizeof(arr) / sizeof(int);
    int element;
    cout << "Enter an element" << endl;
    cin >> element;

    firstOccurence(arr, size, element);
    lastOccurence(arr, size, element);

    return 0;
}