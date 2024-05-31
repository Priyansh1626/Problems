#include <iostream>
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

void deleteDuplicate(Node *&head)
{
    if (head == NULL)
        return;
    Node *curr = head;
    Node *prev = NULL;
    Node *forward = NULL;
    map<int, bool> present;

    while (curr != NULL)
    {
        if (present[curr->data] == true)
        {
            Node *temp = curr;
            forward = curr->next;
            prev->next = forward;
            delete curr;
            curr = forward;
        }
        else
        {
            present[curr->data] = true;
            forward = curr->next;
            prev = curr;
            curr = forward;
        }
    }
}

int main()
{
    Node *node1 = new Node(4);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 3);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 9);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    insertAtHead(head, 9);

    print(head);

    deleteDuplicate(head);

    print(head);

    return 0;
}
