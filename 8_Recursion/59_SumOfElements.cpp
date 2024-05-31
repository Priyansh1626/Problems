// Through recursion find the sum of the elements from an array

#include <iostream>
using namespace std;

int getSum(int *arr, int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    int sum = arr[0] + getSum(arr + 1, n - 1);
    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    int sum = getSum(arr, n);
    cout << sum << endl;
    return 0;
}
