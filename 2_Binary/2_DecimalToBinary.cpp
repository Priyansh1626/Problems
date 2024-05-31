#include <iostream>
#include <math.h>
using namespace std;

// positive input
    void decToBin(int n)
    {
        int ans = 0;
        int i = 0;
        while (n != 0)
        {
            int bit = n & 1;
            ans = (bit * pow(10, i)) + ans;
            n = n >> 1;
            i++;
        }
        cout << ans << endl;
    }

// negative input
void negDec(int n)
{
    n = abs(n);
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    int binary[10];
    int count = 0;
    int j = 0;
    int ans2 = ans;
    int digit = 0;
    while (ans2 != 0)
    {
        digit = ans2 % 10;
        binary[j] = digit;
        j++;
        count++;
        ans2 = ans2 / 10;
    }
    for (int i = 0; i < count / 2; i++)
    {
        swap(binary[i], binary[count - i - 1]);
    }
    // for (int i = 0; i < count; i++)
    // {
    //     cout << binary[i] << " ";
    // }
    // cout << endl;
    int one[10];
    int two[10];
    for (int i = 0; i < count; i++)
    {
        if (binary[i] == 0)
            one[i] = 1;
        else
            one[i] = 0;
    }
    // for (int i = 0; i < count; i++)
    // {
    //     cout << one[i] << " ";
    // }
    // cout << endl;
    int carry = 1;
    for (int i = count; i >= 0; i--)
    {
        if (one[i] == 1 && carry == 1)
            two[i] = 0;
        else if (one[i] == 0 && carry == 1)
        {
            two[i] = 1;
            carry = 0;
        }
        else
        {
            two[i] = one[i];
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << two[i];
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;

    if (n >= 0)
    {
        decToBin(n);
    }
    else
    {
        negDec(n);
    }
    return 0;
}