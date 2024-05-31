// Find the triplet from an array whose sum is K.

#include <iostream>
using namespace std;

void triplet(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == element)
                {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    int element;
    cout << "Enter the triplet sum u want" << endl;
    cin >> element;
    triplet(arr, size, element);
    return 0;
}