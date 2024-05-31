#include <iostream>
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

Node *reverseInGrp(Node *&head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < n)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if (next != NULL)
    {
        head->next = reverseInGrp(next, n);
    }

    return prev;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 6);

    print(head);

    head = reverseInGrp(head, 2);

    print(head);
    // reverseIterative(head);

    return 0;
}