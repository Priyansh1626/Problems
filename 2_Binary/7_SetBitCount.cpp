// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

#include <iostream>
using namespace std;

int setBitCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "Number of setBits are " << setBitCount(n);

    return 0;
}