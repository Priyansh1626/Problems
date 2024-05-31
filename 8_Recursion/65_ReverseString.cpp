#include <iostream>
using namespace std;

void reverse(int i, int j, string &str)
{
    if (i > j)
    {
        return;
    }

    swap(str[i++], str[j--]);

    reverse(i, j, str);
}

int main()
{
    string str = "abcdefg";
    cout << str << endl;
    reverse(0, str.length() - 1, str);
    cout << str << endl;
    return 0;
}