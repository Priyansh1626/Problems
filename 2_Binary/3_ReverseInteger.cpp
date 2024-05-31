// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

#include <iostream>
using namespace std;

int revInt(int n)
{
    int ans = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
        {
            return 0;
        }
        ans = (ans * 10) + digit;
        n = n / 10;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "Rev is " << revInt(n);

    return 0;
}