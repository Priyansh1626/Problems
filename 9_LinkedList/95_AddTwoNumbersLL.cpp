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

Node *reverse(Node *&head)
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

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *temp = new Node(d);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL && second != NULL)
    {
        int sum = carry + first->data + second->data;
        int digit = sum % 10;

        // create node and add to ans LL
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        first = first->next;
        second = second->next;
    }

    while (first != NULL)
    {
        int sum = carry + first->data;
        int digit = sum % 10;

        // create node and add to ans LL
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        first = first->next;
    }

    while (second != NULL)
    {
        int sum = carry + second->data;
        int digit = sum % 10;

        // create node and add to ans LL
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        second = second->next;
    }

    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;

        // create node and add to ans LL
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10;
    }
    return ansHead;
}

Node *addTwoNumbers(Node *first, Node *second)
{
    // reverse input LL
    first = reverse(first);
    second = reverse(second);

    // add 2 LL
    Node *ans = add(first, second);

    // reverse the answer LL
    ans = reverse(ans);

    return ans;
}

int main()
{
    Node *head1 = new Node(0);

    insertAtHead(head1, 4);
    insertAtHead(head1, 3);
    insertAtHead(head1, 2);
    insertAtHead(head1, 1);

    Node *head2 = new Node(0);

    insertAtHead(head2, 8);
    insertAtHead(head2, 7);
    insertAtHead(head2, 6);
    insertAtHead(head2, 5);

    print(head1);
    print(head2);

    Node *ansHead = addTwoNumbers(head1, head2);

    print(ansHead);

    return 0;
}
