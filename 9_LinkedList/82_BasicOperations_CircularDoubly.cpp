#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            this->next = NULL;
        }
    }
};

void print(Node *tail)
{
    Node *temp = tail;
    do
    {
        temp = temp->next;
        cout << temp->data << " ";
    } while (temp != tail);
}

void insertAtHead(Node *&tail, Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (tail == NULL)
    {
        tail = newNode;
        head = tail;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void insertAtTail(Node *&tail, Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (tail == NULL)
    {
        tail = newNode;
        head = tail;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteAtPosi(Node *&head, int posi)
{
    Node *current = head;
    Node *after = head->next;
    if (posi == 1)
    {
        delete current;
        head = after;
    }
    else
    {
        for (int i = 1; i < posi - 1; i++)
        {
            current = current->next;
            after = after->next;
        }
        current->next = after->next;
        after->next = NULL;
        delete after;
    }
}

int main()
{
    Node *tail = NULL;
    Node *head = NULL;

    insertAtHead(tail, head, 1);
    insertAtHead(tail, head, 2);
    insertAtHead(tail, head, 3);
    insertAtTail(tail, head, 0);
    insertAtTail(tail, head, -1);

    print(tail);

    deleteAtPosi(head, 2);

    print(tail);

    return 0;
}