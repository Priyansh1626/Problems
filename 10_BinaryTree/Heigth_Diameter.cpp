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

int getHeight(node * root){

    if(root == NULL){
        return 0;
    }

    int left = getHeight(root->left);
    int right = getHeight(root->right);
    int ans = max(left, right) + 1;

    return ans;
}

pair<int,int> getDiameter(node * root){

    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = getDiameter(root->left);
    pair<int, int> right = getDiameter(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int, int> ans;

    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second , right.second) + 1;
    return ans; 
}

int main () {

    node *root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 16 -1 -1
    levelOrder(root);
    int heightOfTree = getHeight(root);
    cout << "Height of tree : " << heightOfTree << endl;
    int diamater = getDiameter(root).first;
    cout << "Diameter : " << diamater << endl;

    return 0;
}



