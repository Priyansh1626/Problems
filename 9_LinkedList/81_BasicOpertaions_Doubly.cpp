#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int n)
    {
        this->data = n;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->prev = NULL;
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
    head->prev = temp;
    head = temp;
}

void insertAtTail(Node *&tail, int n)
{
    Node *temp = new Node(n);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosi(Node *&head, Node *tail, int posi, int n)
{
    if (posi == 1)
    {
        insertAtHead(head, n);
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < posi - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, n);
    }
    Node *newNode = new Node(n);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
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
        Node *temp = head;
        int cnt = 1;
        while (cnt < posi)
        {
            temp = temp->next;
            cnt++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    deleteNode(head, 1);

    print(head);

    return 0;
}