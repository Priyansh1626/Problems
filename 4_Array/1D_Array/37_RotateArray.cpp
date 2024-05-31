// Rotate an array by k

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void rotate(vector<int> &v, int k)
{
    vector<int> temp(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        temp[(i + k) % v.size()] = v[i];
    }
    v = temp;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    printVector(v);

    rotate(v, 1);

    printVector(v);
    return 0;
}