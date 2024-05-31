// Through recursion apply Linear search

#include <iostream>
#include <vector>
using namespace std;

bool linearSearch(int *arr, int n, int key)
{
    if (n == 0)
        return false;
    if (arr[0] == key)
        return true;
    else
        return linearSearch(arr + 1, n - 1, key);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int element;
    cout << "Enter the element" << endl;
    cin >> element;
    if (linearSearch(arr, n, element))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
