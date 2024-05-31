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

Node *solve(Node *&first, Node *&second)
{
    // if only 1 element in first ll
    if (first->next == NULL)
    {
        first->next = second;
        return first;
    }

    if (first == NULL)
    {
        return second;
    }

    if (second == NULL)
    {
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr1->data <= curr2->data) && (curr2->data <= next1->data))
        { // placing ll2 node in between ll1 node
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        { // shifting pointers
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node *merge(Node *&first, Node *&second)
{
    if (first->data <= second->data)
        return solve(first, second);
    else
        return solve(second, first);
}

int main()
{
    Node *node1 = new Node(9);
    Node *head = node1;

    insertAtHead(head, 9);
    insertAtHead(head, 3);
    insertAtHead(head, 1);
    insertAtHead(head, 0);

    Node *node_1 = new Node(12);
    Node *head2 = node_1;

    insertAtHead(head2, 6);
    insertAtHead(head2, 4);
    insertAtHead(head2, 2);

    print(head);
    print(head2);

    Node *NewHead = merge(head, head2);

    print(NewHead);

    return 0;
}
