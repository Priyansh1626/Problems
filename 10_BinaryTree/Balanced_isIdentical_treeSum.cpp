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

int getHeight(node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);
    int ans = max(left, right) + 1;

    return ans;
}

pair<bool, int> isBalanced(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> left = isBalanced(root->left);
    pair<bool, int> right = isBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    
    ans.second = max(left.second , right.second) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}

bool isIdentical(node * r1, node * r2) {
    if(r1 == NULL && r2 == NULL)
        return true;
    if(r1 == NULL && r2 != NULL)
        return false;
    if(r1 != NULL && r2 == NULL)
        return false;
    
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value)
        return true;
    else 
        return false;
}

pair<bool,int> treeSum(node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool,int> leftAns = treeSum(root->left);
    pair<bool,int> rightAns = treeSum(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condtn = root->data == leftAns.second + rightAns.second;

    if(left && condtn && right){
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else{
        ans.first = false;
    }
    return ans;
}

int main()
{
    
    node *root = buildTree(root);
    node *root2 = buildTree(root2);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 16 -1 -1
    levelOrder(root);  
    // 1 3 7 -1 -1 11 -1 -1 5 17 8 -1 -1 16 -1 -1 -1 -1
    levelOrder(root2);   
    cout << "Balanced : " << isBalanced(root2).first << endl;
    cout << "Identical : " << isIdentical(root,root2);
    
    return 0;
}
