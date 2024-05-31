#include <iostream>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }

    int digit = n % 10;
    n = n / 10;

    sayDigit(n, arr);

    cout << arr[digit - 1] << " ";
}

int main()
{
    cout << "Enter a number" << endl;
    int n;
    cin >> n;
    string arr[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    sayDigit(n, arr);

    return 0;
}