// Given an integer number, return the difference between the product and the sum of its digit.

#include <iostream>
using namespace std;

int answer(int n)
{
    int product = 1;
    int sum = 0;
    while (n !=0)
    {
        int digit = n % 10;
        product *= digit;
        sum += digit;
        n = n / 10;
    }
    int answer = product - sum;
    return answer;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "Product and sum of its digit is " << answer(n) << endl;
    return 0;
}