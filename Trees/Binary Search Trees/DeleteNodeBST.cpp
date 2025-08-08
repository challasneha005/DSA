//DELETE NODE IN BINARY SEARCH TREE O(h) , O(h)
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node* findLastRight(Node* root){
    if(root->right == NULL)
        return root;
    return findLastRight(root->right);
}
Node* helper(Node* root){
    if(root->left == NULL)
        return root->right;
    else if(root->right == NULL)
        return root->left;
    Node* rightChild = root->right;
    Node* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left; 
}
Node* deleteNode(Node* root,int key){
    if(root == NULL)
        return NULL;
    if(root->data == key)
        return helper(root);
    Node* dummy = root;
    while(root != NULL){
        if(root->data > key){
            if(root->left != NULL && root->left->data == key){
                root->left = helper(root->left);
                break;
            }
            else
                root = root->left;
        }
        else{
            if(root->right != NULL && root->right->data == key){
                root->right = helper(root->right);
                break;
            }
            else
                root = root->right;
        }
    }
    return dummy;
}
void printInorder(Node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    int val = 6;
    printInorder(root);
    cout << endl;
    root = deleteNode(root, val);
    cout << "Deleted Node " << val << endl;
    printInorder(root);
    return 0;
}