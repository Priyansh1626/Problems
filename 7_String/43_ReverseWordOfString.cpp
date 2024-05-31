// Reverse words in a string

#include <iostream>
// #include <vector>
using namespace std;

void print(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(char arr[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        swap(arr[s++], arr[e--]);
    }

    s = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ' ')
        {
            int k = i - 1;

            while (s <= k)
            {
                swap(arr[s++], arr[k--]);
            }
            s = i + 1;
        }
        if (i == n - 1)
        {
            int k = i;
            while (s <= k)
            {
                swap(arr[s++], arr[k--]);
            }
        }
    }
}

int main()
{
    char s[] = {'t', 'h', 'e', ' ', 's', 'k', 'y', ' ', 'i', 's', ' ', 'b', 'l', 'u', 'e'};
    // output = { 'b','l','u','e',' ','i','s',' ','s','k','y','e',' ','t','h','e'};

    int size = sizeof(s) / sizeof(char);

    print(s, size);

    reverse(s, size);

    print(s, size);
    return 0;
}

// reversing invididual word from a string
// I/P => hello guys
// O/P => looeh syug

// string reverse(string x)
// {
//     int i = 0;
//     int j = x.length() - 1;
//     while (i <= j)
//     {
//         swap(x[i], x[j]);
//         i++;
//         j--;
//     }
//     x.push_back(' ');
//     return x;
// }

// int main()
// {
//     string s, x;
//     vector<string> v;
//     getline(cin, s);
//     int i = 0;
//     int j = s.length() - 1;
//     while (s[i] != '\0')
//     {
//         if (s[i] != ' ')
//         {
//             x.push_back(s[i]);
//         }
//         else if (s[i] == ' ')
//         {
//             v.push_back(reverse(x));
//             x.clear();
//         }
//         i++;
//     }
//     v.push_back(reverse(x));
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i];
//     }
//     return 0;
// }