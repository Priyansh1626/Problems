// Remove adjecents duplicates characters from an array.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void print(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<char> removeDuplicates(char arr[], int n)
{
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        char ch = arr[i];
        if (st.empty())
        {
            st.push(ch);
        }
        else
        {
            if (st.top() == ch)
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        vector<char> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
}

int main()
{
    char arr[] = {'a', 'a', 'b', 'c', 'c', 'b', 'd', 'e'};
    int size = sizeof(arr) / sizeof(char);

    print(arr, size);

    vector<char> ans = removeDuplicates(arr, size);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
