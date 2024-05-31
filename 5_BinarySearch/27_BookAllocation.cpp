// Book Allocation Plroblem. There is an array of books in which elements represents book pages. There are M students and N books. Conditions:-
// (1) Each student gets at least one book.
// (2) Each book should be allocated toa student.
// (3) Book allocations should be in contigous manner.
// You have to allocate the book to M students such that the maximum number of pages assigned to a student is minimum.

#include <iostream>
#include <vector>
using namespace std;

bool isPossibleSolution(vector<int> arr, int n, int m, int mid)
{
    int pageSum = 0;
    int studentCount = 1;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = 0;
            pageSum += arr[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> arr, int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossibleSolution(arr, n, m, mid))
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
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    int ans = allocateBooks(v, 4, 2);
    cout << ans << endl;
    return 0;
}