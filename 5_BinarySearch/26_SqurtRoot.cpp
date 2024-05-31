// Find a squreRoot of a number using binary search

#include <iostream>
using namespace std;

int squreRootInt(int k)
{
    int s = 0, e = k, mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        int squre = mid * mid;
        if (squre == k)
        {
            return mid;
        }
        if (squre < k)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int k, int precision, int rootInt)
{
    double factor = 1;
    double finalRoot = rootInt;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = rootInt; j * j < k; j = j + factor)
        {
            finalRoot = j;
        }
    }
    return finalRoot;
}

int main()
{
    int k;
    cout << "Enter a number u want sqreRoot of" << endl;
    cin >> k;
    int rootInt = squreRootInt(k);
    cout << "Final root is " << morePrecision(k, 3, rootInt);

    return 0;
}