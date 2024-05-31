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

// TC - O(n) || SC - O(n)
bool detectCycle(Node *head)
{
    if (head == NULL)
        return false;

    map<Node *, bool> visited;
    Node *temp = head;

    while (temp != NULL)
    {
        // checking if the node is visited or not
        if (visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Floyd's cycle detection algo
// TC - O(n) || SC - O(1)
bool floydsDetectLoop(Node *head)
{

    if (head == NULL)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (slow == fast)
            return true;
    }
    return false;
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

    // 5 4 3 2 1
    // h       t

    // creating cycle here
    tail->next = head->next->next;

    // print(head);

    (floydsDetectLoop(head)) ? cout << "Cycle present" : cout << "No cycle present";

    return 0;
}