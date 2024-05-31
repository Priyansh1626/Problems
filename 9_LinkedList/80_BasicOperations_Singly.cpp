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
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
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

void insertAtTail(Node *&tail, int n)
{
    Node *temp = new Node(n);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int n)
{
    Node *temp = head;
    if (position == 1)
    {
        insertAtHead(head, n);
        return;
    }
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, n);
        return;
    }
    Node *newNode = new Node(n);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&head, int posi)
{
    if (posi == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < posi)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;
    insertAtPosition(head, tail, 2, 3);
    insertAtPosition(head, tail, 1, 1);
    deleteNode(head, 4);
    print(head);
    return 0;
}