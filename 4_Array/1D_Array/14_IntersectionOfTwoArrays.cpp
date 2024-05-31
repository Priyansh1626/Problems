// Two Arrays of size N and M. They are sorted in non-decreasing order. You have to find the intersection of these two arrays.

#include <iostream>
#include <vector>
using namespace std;

// complexity will be O(n^2)
vector<int> Intersection(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int element = arr1[i];
        for (int j = 0; j < m; j++)
        {
            if (element < arr2[j])
            {
                break;
            }
            if (element == arr2[j])
            {
                ans.push_back(element);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    return ans;
}

// complexity will be O(n)
// 2pointers method
vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);

    vector<int> ans = Intersection(v1, v2, 3, 3);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans.at(i) << " ";
    }

    return 0;
}