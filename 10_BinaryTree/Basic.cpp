#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
        int data;
        node * left;
        node * right;
    
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node * buildTree(node * root) {

    cout << " Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for left Node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right Node of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void inOrder(node *root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root){
    if(root == NULL) return;
    cout << root->data << " " << endl;
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(node *root){
    if(root == NULL) return;
    inOrder(root->left);
    inOrder(root->right);
    cout << root->data << " " << endl;
}

void levelOrder(node *root){
    queue<node *> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;

            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}

void buildTreeFromLevelOrder(node * &root){
    queue<node *> q;

    cout << "Enter the root node data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);   

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout << "Enter left node data of " << temp->data << endl;
        int leftNode;
        cin >> leftNode;

        if(leftNode != -1) {
            temp -> left = new node(leftNode);
            q.push(temp -> left);
        }

        cout << "Enter right node data of " << temp->data << endl;
        int rightNode;
        cin >> rightNode;

        if(rightNode != -1) {
            temp -> right = new node(rightNode);
            q.push(temp -> right);
        }
    }
}

int main () {

    // node *root = buildTree(root);
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // // inOrder(root);
    // levelOrder(root);

    node* root = NULL;
    buildTreeFromLevelOrder(root);

    levelOrder(root);

    return 0;
}



