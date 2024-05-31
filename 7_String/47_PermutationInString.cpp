// Permutation in a string
// Given 2 string s1 and s2 , return true if s2 contanins a permutation of s1, or false otherwise.
// in other words , return true if one of s1's permutation is the substring of s2

#include <iostream>
using namespace std;

bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return 0;
        }
    }
    return 1;
}

int checkInclusion(string s1, string s2)
{
    // character count array
    int count1[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // traverse in s2 string in window size s2 length and compare
    int i = 0;
    int windowSize = s1.length();
    int count2[26] = {0};
    // running for first window
    while (i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (checkEqual(count1, count2))
    {
        return 1;
    }
    // running whindows in whole s2
    while (i < s2.length())
    {
        char newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        char oldChar = s2[i - windowSize];
        index = oldChar - 'a';
        count2[index]--;

        i++;

        if (checkEqual(count1, count2))
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    string s1 = "ab";
    string s2 = "eidabaooo";
    cout << "Is s1's permutation is the substring of s2 : " << checkInclusion(s1, s2) << endl;
    return 0;
}