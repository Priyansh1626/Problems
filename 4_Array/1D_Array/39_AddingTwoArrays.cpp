// Add two arrays

#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;
    while (s < e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    vector<int> ans;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[i];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i > 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (j > 0)
    {
        int sum = a[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }
    return ans;
}

int main()
{
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    vector<int> sumrev = findArraySum(v1, v1.size(), v2, v2.size());
    vector<int> sum = reverse(sumrev);

    for (int i : sum)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}