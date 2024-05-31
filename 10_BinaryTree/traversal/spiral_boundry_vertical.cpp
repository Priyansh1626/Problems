#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    cout << " Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left Node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right Node of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrder(node *root)
{
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void traverseSprial(node *root)
{
    vector<int> result;
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {

            node *frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }

        leftToRight = !leftToRight;

        for (auto i : ans)
        {
            result.push_back(i);
        }
    }

    for (auto i : result)
    {
        cout << i << " ";
    }

    return;
}

void traverseLeft(node *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    result.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, result);
    }
    else
    {
        traverseLeft(root->right, result);
    }
}

void traverseLeaf(node *root, vector<int> &result)
{

    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        result.push_back(root->data);
    }

    traverseLeaf(root->left, result);
    traverseLeaf(root->right, result);
}

void traverseRight(node *root, vector<int> &result)
{
    if (root == NULL)
    {
        return;
    }
    if (root->right == NULL && root->left == NULL)
    {
        return;
    }
    if(root->right)
        traverseRight(root->right, result);
    else 
        traverseRight(root->left, result);
    result.push_back(root->data);
}

void traverseBoundry(node *root)
{
    vector<int> result;
    traverseLeft(root, result);

    traverseLeaf(root->left, result);
    traverseLeaf(root->right, result);

    traverseRight(root->right, result);

    for (auto i : result)
    {
        cout << i << " ";
    }
}

int main()
{
    node *root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrder(root);
    cout << endl;
    // traverseSprial(root);
    traverseBoundry(root);

    return 0;
}
