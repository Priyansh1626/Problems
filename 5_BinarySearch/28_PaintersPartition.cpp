// Painters Partition Problem. there are m numbers of painters ans u have to paint the boards such that it will took minimum time .
// (1) Each boards be painted.
// (2) contigous boards shoult b allocated.

#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int painterCount = 1;
    int boardSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (boardSum + arr[i] <= mid)
        {
            boardSum += arr[i];
        }
        else
        {
            painterCount++;
            if (painterCount > m || arr[i] > mid)
            {
                return false;
            }
            boardSum = 0;
            boardSum += arr[i];
        }
    }
    return true;
}

int minTime(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(48);
    v.push_back(90);
    // v.push_back(30);
    // v.push_back(40);
    int ans = minTime(v, 2, 2);
    cout << ans << endl;
    return 0;
}