#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int n)
{
    Node *temp = new Node(n);
    temp->next = head;
    head = temp;
}

// TC - O(n) SC - O(n)
// bool checkPalindrome(vector<int> arr)
// {
//     int n = arr.size();
//     int s = 0;
//     int e = n - 1;

//     while (s <= e)
//     {
//         if (arr[s] != arr[e])
//         {
//             return 0;
//         }
//         s++;
//         e--;
//     }
//     return 1;
// }
// bool isPalindrome(Node *head)
// {
//     vector<int> arr;

//     Node *temp = head;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }
//     return checkPalindrome(arr);
// }

// TC - O(N) SC - O(1)
Node *getMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    // find middle
    Node *middle = getMid(head);

    // reverse list after middle
    Node *temp = middle->next;
    middle->next = reverse(temp);

    // compare both the halfs
    Node *head1 = head;
    Node *head2 = middle->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}
int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;

    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    if (isPalindrome(head))
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}
