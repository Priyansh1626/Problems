// Agressive Cows
// arrys of stalls is given u have to place the cows such that the minimum distance between stalls must be maximum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> stalls, int n, int m, int mid)
{
    int cowCount = 1;
    int lastPosi = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPosi >= mid)
        {
            cowCount++;
            if (cowCount == m)
            {
                return true;
            }
            lastPosi = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> stalls, int n, int m)
{
    sort(stalls.begin(), stalls.end());

    int s = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossible(stalls, n, m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(7);
    int distance = aggressiveCows(v, 5, 2);
    cout << distance << endl;
    return 0;
}