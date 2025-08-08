//CHECK BINARY SEARCH TREE O(n) , O(h)
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
bool isValidBST(Node* root,long minval,long maxval){
    if(root == NULL)
        return true;
    if(root->data >=maxval || root->data <=minval)
        return false;
    return isValidBST(root->left,minval,root->data) &&
            isValidBST(root->right,root->data,maxval);
}
bool isValid(Node* root){
    return isValidBST(root,LONG_MIN,LONG_MAX);
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

    if(isValid(root))
        cout << "It is a Binary Search Tree." << endl;
    else
        cout << "It is not a Binary Search Tree." << endl;
    return 0;
}