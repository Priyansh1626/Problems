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

// counting and replace value TC-O(n) SC-O(1)
//  void sort(Node *&head)
//  {
//      if (head == NULL)
//          return;
//      Node *temp = head;
//      int zeroCnt = 0, oneCnt = 0, twoCnt = 0;
//      while (temp != NULL)
//      {
//          if (temp->data == 0)
//              zeroCnt++;
//          else if (temp->data == 1)
//              oneCnt++;
//          else if (temp->data == 2)
//              twoCnt++;
//          temp = temp->next;
//      }
//      temp = head;
//      while (temp != NULL)
//      {
//          if (zeroCnt != 0)
//          {
//              temp->data = 0;
//              zeroCnt--;
//          }
//          else if (oneCnt != 0)
//          {
//              temp->data = 1;
//              oneCnt--;
//          }
//          else if (twoCnt != 0)
//          {
//              temp->data = 2;
//              twoCnt--;
//          }
//          temp = temp->next;
//      }
//  }

// if Data replacement is not allowed we will change links TC-O(n) SC-O(1)
void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

void sort(Node *&head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // creating seperacte ll for 0 1 2
    while (curr != NULL)
    {
        int val = curr->data;
        if (val == 0)
        {
            insertAtTail(zeroTail, curr);
        }
        if (val == 1)
        {
            insertAtTail(oneTail, curr);
        }
        if (val == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr->next;
    }

    // merge all three lists
    if (oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        zeroTail->next = twoHead->next;
    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    head = zeroHead->next;
}

int main()
{
    Node *node1 = new Node(0);
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 0);
    insertAtHead(head, 2);
    insertAtHead(head, 0);
    insertAtHead(head, 1);

    print(head);

    sort(head);

    print(head);
    return 0;
}