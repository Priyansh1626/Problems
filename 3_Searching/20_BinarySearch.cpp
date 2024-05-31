#include <iostream>
using namespace std;

int search(int *arr, int size, int element)
{
    int s = 0, e = size - 1, mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (element == arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 55, 60};
    int size = sizeof(arr) / sizeof(int);
    cout << "Enter the element " << endl;
    int element;
    cin >> element;
    int found = search(arr, size, element);
    if (found)
    {
        cout << "Elemenet found" << found << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}
