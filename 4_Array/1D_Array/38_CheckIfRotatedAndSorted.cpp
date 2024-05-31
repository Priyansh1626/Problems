// Check if array is sorted and rotated

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &v)
{
    int count = 0;
    int n = v.size();
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
        {
            count++;
        }
    }
    if (v[n - 1] > v[0])
    {
        count++;
    }
    return count <= 1;
}

int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(4);
    v.push_back(6);

    if (check(v))
    {
        cout << "It is sorted and rotated array" << endl;
    }
    else
    {
        cout << "It is not sorted and rotated array" << endl;
    }

    return 0;
}