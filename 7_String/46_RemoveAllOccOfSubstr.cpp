// Remove all occurrences of a substring

#include <iostream>
using namespace std;

string removeOccOfSubStr(string s, string part)
{
    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main()
{
    string str = "daabcbaabcbc";
    string part = "abc";

    cout << "After removing " << part << " :- " << removeOccOfSubStr(str, part) << endl;

    return 0;
}