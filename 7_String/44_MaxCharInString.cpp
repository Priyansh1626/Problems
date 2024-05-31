// Return a character whose count is maximum in a string

#include <iostream>
using namespace std;

char maxOccChar(string s)
{
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        int number = 0;
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';
        }
        else
        {
            number = ch - 'A';
        }
        arr[number]++;
    }

    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = ans + 'a';
    return finalAns;
}

int main()
{
    string s;
    cout << "Enyter a string" << endl;
    getline(cin, s);
    cout << "maximum occuring character in this string is : " << maxOccChar(s) << endl;

    return 0;
}