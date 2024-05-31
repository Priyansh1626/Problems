// String compression
// For each group of consecutive repeating characters:-
// (1) If the group's length is 1 , append the character to s
// (2) Otherwise append the character followed by its group length
// The compressed string s should not be returned seperately but instead be stored in the input array.
// After u dont modifying the input array, return the length of the array.

#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int i = 0;
    int ansIndex = 0;
    int n = chars.size();

    while (i < n)
    {
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }
        chars[ansIndex++] = chars[i];

        int count = j - i;

        if (count > 1)
        {
            // converting count into single digit and saving in answer
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[ansIndex++] = ch;
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    vector<char> v;
    v.push_back('a');
    v.push_back('a');
    v.push_back('b');
    v.push_back('b');
    v.push_back('c');
    v.push_back('c');
    v.push_back('c');
    v.push_back('d');
    v.push_back('d');
    v.push_back('d');
    cout << "After compressing the length is : " << compress(v) << endl;
    return 0;
}
