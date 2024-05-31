#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element;
    cout << "Element to be searched?" << endl;
    cin >> element;
    int found = linearSearch(arr, size, element);
    if (found)
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    // cout<<found;

    return 0;
}