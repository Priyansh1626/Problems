// Sort 0,1,2.

#include <iostream>
using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sort(int *arr, int size)
{
    int i = 0;
    int k = 0;
    int j = size - 1;

    while (i < j)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[k]);
            k++;
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[j]);
            j--;
        }
        else
            i++;
    }
}

int main()
{
    int arr[] = {0, 0, 2, 2, 0, 1, 1, 0, 2, 1, 0};
    int size = sizeof(arr) / sizeof(int);

    sort(arr, size);
    print(arr, size);
    return 0;
}