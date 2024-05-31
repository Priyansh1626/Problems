#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Enter a number" << endl;
    int n;
    cin >> n;
    int a = 100, b = 50, c = 10, d = 1, e = 0, f = 0, g = 0, h = 0;
    int m = n;

    if (m > a)
    {
        e = m / a;
        m = m % a;
    }
    if (m > b)
    {
        f = m / b;
        m = m % b;
    }
    if (m > c)
    {
        g = m / c;
        m = m % c;
    }
    if (m > d)
    {
        h = m / d;
        m = m % d;
    }
    cout << e << " " << f << " " << g << " " << h;

    return 0;
}