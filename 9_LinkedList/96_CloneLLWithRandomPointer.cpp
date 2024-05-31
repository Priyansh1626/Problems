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

int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;

    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    return 0;
}
