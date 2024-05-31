// Reverse a string

#include <iostream>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char arr[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        swap(arr[s++], arr[e--]);
    }
}

int main()
{
    char name[20];
    cout << "Enter your name" << endl;
    cin >> name;
    int length = getLength(name);
    reverse(name, length);
    cout << "Reverse of your name is: " << name << endl;
    return 0;
}