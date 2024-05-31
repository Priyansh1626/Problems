// (SieveOfEratosthenis algorithm)
// Return the number of prime numbers that are strictly less than n using

#include <iostream>
#include <vector>
using namespace std;

int countPrime(int n) // O( n * log(logn) )
{
    int count = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;

            for (int j = i * 2; j < n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    cout << "There are total " << countPrime(n) << " prime numbers less than " << n << endl;
    return 0;
}
