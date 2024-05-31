// Through recursion
// You have been given a number of stairs. Initially you are at the 0th stair, ans you need to reach the Nth stair. Each time you can either climb one step or two step. You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.

#include <iostream>
using namespace std;

int ways(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int ans = ways(n - 1) + ways(n - 2);
    return ans;
}

int main()
{
    cout << "Enter tatal number of steps" << endl;
    int num;
    cin >> num;
    cout << "Total ways are " << ways(num);
    return 0;
}