// You are givern an array 'ARR' of size N containing each number between (1 and N-1) at least once. There is a single integer value that is present in the array twice. Your task is to find that duplicate integer value present in an array.

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    int duplicate = findDuplicate(v);
    cout << "Duplicate term is " << duplicate << endl;
    return 0;
}