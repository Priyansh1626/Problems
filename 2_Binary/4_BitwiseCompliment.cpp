// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation

#include <iostream>
using namespace std;

int bitwiseCompliment(int n)
{
    int m = n;
    int mask = 0;
    if (m == 0)
    {
        return 1;
    }
    while (m != 0)
    {
        m = m >> 1;
        mask = (mask << 1) | 1;
    }
    int ans = (~n) & mask;
    return ans;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "Compliment is " << bitwiseCompliment(n) << endl;
    return 0;
}