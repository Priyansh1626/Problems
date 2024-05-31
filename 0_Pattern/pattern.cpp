#include <iostream>
using namespace std;

void p1(int r)
{
    // *
    // **
    // ***
    // ****
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void p2(int r)
{
    // 1
    // 22
    // 333
    // 4444
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}
void p3(int r)
{
    // 1
    // 23
    // 456
    // 78910
    int count = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}
void p4(int r)
{
    // 1
    // 21
    // 321
    // 4321
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i - j + 1 << " ";
        }
        cout << endl;
    }
}
void p5(int r)
{
    // AAA
    // BBB
    // CCC
    for (int i = 1; i <= r; i++)
    {
        char start = 'A' + i - 1;
        for (int j = 1; j <= r; j++)
        {
            cout << start << " ";
        }
        cout << endl;
    }
}
void p6(int r)
{
    // ABC
    // ABC
    // ABC
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            char start = 'A' + j - 1;
            cout << start << " ";
        }
        cout << endl;
    }
}
void p7(int r)
{
    // ABC
    // BCD
    // CDE
    for (int i = 1; i <= r; i++)
    {
        char start = 'A' + i - 1;
        for (int j = 1; j <= r; j++)
        {
            // char start = 'A' + i + j -2 ;
            cout << start;
            start++;
        }
        cout << endl;
    }
}
void p8(int r)
{
    // D
    // CD
    // BCD
    // ABCD
    for (int i = 1; i <= r; i++)
    {
        char start = 'A' + r - i;
        for (int j = 1; j <= i; j++)
        {
            cout << start;
            start++;
        }
        cout << endl;
    }
}
void p9(int r)
{
    //    *
    //   **
    //  ***
    // ****
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= r - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void p10(int r)
{
    // ****
    // ***
    // **
    // *
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= r - i + 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void p11(int r)
{
    // ****
    //  ***
    //   **
    //    *
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= r - i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void p12(int r)
{
    // 1111
    //  222
    //   33
    //    4
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= r - i + 1; k++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void p13(int r)
{
    //    1
    //   22
    //  333
    // 4444
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= r - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void p14(int r)
{
    // 1234
    //  234
    //   34
    //    4
    for (int i = 1; i <= r; i++)
    {
        int count = 1 + i - 1;
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= r - i + 1; k++)
        {
            cout << count;
            count++;
        }
        cout << endl;
    }
}
void p15(int r)
{
    //     1
    //    23
    //   456
    // 78910
    for (int i = 1; i <= r; i++)
    {
        static int count = 1;
        for (int j = 1; j <= r - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << count;
            count++;
        }
        cout << endl;
    }
}
void p16(int r)
{
    //    1
    //   121
    //  12321
    // 1234321
    for (int i = 1; i <= r; i++)
    {
        int count = 1;
        for (int j = 1; j <= r - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << count;
            count++;
        }
        int start = i - 1;
        for (int l = 1; l <= i - 1; l++)
        {
            cout << start;
            start--;
        }
        cout << endl;
    }
}
void p17(int r)
{
    // 1234554321
    // 1234**4321
    // 123****321
    // 12******21
    // 1********1
    for (int i = 1; i <= r; i++)
    {
        int count = 1;
        for (int j = 1; j <= r - i + 1; j++)
        {
            cout << count;
            count++;
        }
        for (int k = 1; k <= (2 * i) - 2; k++)
        {
            cout << "*";
        }
        int start = r - i + 1;
        for (int l = 1; l <= r - i + 1; l++)
        {
            cout << start;
            start--;
        }
        cout << endl;
    }
}
int main()
{
    int i;
    cout << "Enter number or rows" << endl;
    cin >> i;
    p17(i);

    return 0;
}