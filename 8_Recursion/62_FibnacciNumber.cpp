// Through recursion find Febonacci number

#include <iostream>
using namespace std;

int findFib(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    int ans = findFib(n - 1) + findFib(n - 2);
    return ans;
}

int main()
{
    int num;
    cout << "Enter the number" << endl;
    cin >> num;
    int ans = findFib(num);
    cout << ans << endl;
    return 0;
}
