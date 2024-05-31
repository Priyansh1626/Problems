// Move Zeros to right and shift other elements to the lest in the same order

#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> moveZeros(vector<int> v)
{
    int nonZero = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            swap(v[i], v[nonZero]);
            nonZero++;
        }
    }
    return v;
}

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(12);
    v.push_back(5);
    v.push_back(0);
    printVector(v);

    vector<int> ans = moveZeros(v);

    printVector(ans);
    return 0;
}