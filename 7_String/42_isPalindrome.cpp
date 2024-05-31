// Given string is palindrom or not. And string characters are not case sensitive
// If the string has symbols skip it(not done)
// character and numbers are only allowed

#include <iostream>
using namespace std;

char toLowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

bool checkPalindrome(char arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        if (!isalnum(arr[start]))
        {
            start++;
        }
        else if (!isalnum(arr[end]))
        {
            end--;
        }
        else
        {
            if (tolower(arr[start]) != tolower(arr[end]))
            {
                return false;
            }
            start++;
            end--;
        }
    }
    return 1;
}

int main()
{
    // char arr[] = {'n', 'a', 'a', 'i'};
    char arr[20];
    cout << "Enter your name" << endl;
    cin >> arr;
    int n = getLength(arr);
    char ch;

    bool got = checkPalindrome(arr, n);
    if (got)
    {
        cout << "It is a palindrom string" << endl;
    }
    else
    {
        cout << "It is not a palindrom string" << endl;
    }

    return 0;
}