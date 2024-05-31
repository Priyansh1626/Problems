// Given an integer n, return true if it is a power of two. Otherwise, return false

#include<iostream>
using namespace std;

bool checkPow(int n){
    int ans = 1;
        for(int i=0 ; i<31 ; i++){
           if(ans == n){
                return 1;
            }
            if(ans < INT_MAX/2)
            ans = ans * 2;
        }
    return 0;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << n << " is in power of 2 ? => " << checkPow(n) << endl;

    return 0;
}