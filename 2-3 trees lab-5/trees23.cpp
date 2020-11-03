#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int lval, rval;
        Node* left;
        Node* middle;
        Node* right;
};

Node* createNode(int val){
    Node* newnode = new Node();
    newnode->lval = val;
    newnode->rval = -1;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->middle = NULL;
    return newnode;
}

Node* insert(Node* root, int val){
    if(root == NULL) return createNode(val);
    if(root->rval == -1 && val > root->lval){
        root->rval = val;
    }
    else{
        if(val < root->lval)
            root->left = insert(root->left, val);
        else if(val > root->rval)
            root->right = insert(root->right, val);
        else if(val < root->rval && val > root->lval)
            root->middle = insert(root->middle, val);
    }
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL) return root;
    if(val < root->lval)
        root->left = deleteNode(root->left, val);
    else if(val < root->rval && val > root->lval)
        root->middle = deleteNode(root->middle, val);
    else if(val > root->rval)
        root->right = deleteNode(root->right, val);
    else if(val == root->lval || val == root->rval){
        if(root->lval == val){
            if(root->left == NULL){
                cout << "deleted" << endl;
                root->lval = root->rval;
                root->rval = -1;
            }else{
                root->lval = root->left->rval;
                root->left->rval = -1;   
            }
        }else if(root->rval == val){
            if(root->right == NULL){
                root->rval = -1;
            }else{
                root->rval = root->right->rval;
                root->right->rval = -1;   
            }
        }
    }
    return root;
}

void printPreorder(Node* root){
    if(root == NULL){
        return;
    }
    if(root->rval == -1 && root->lval == -1){
        return;
    }
    if(root->rval == -1){
        cout << root->lval << ":" << "- ";
    }else{
        cout << root->lval << ":" << root->rval << " ";   
    }
    printPreorder(root->left);
    printPreorder(root->middle);
    printPreorder(root->right);
}

int main(){
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 80);
    root = insert(root, 70);
    root = insert(root, 50);
    printPreorder(root);
    cout << endl;
    deleteNode(root, 10);
    printPreorder(root);
    cout << endl;
    return 0;
}