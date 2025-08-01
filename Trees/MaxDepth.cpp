//MAXIMUM DEPTH OF BINARY TREE  O(n) , O(n)
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
int maxDepth (Node* root){
    if(root == NULL)
        return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return max(lh,rh)+1;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    root->left->right->right->right->right = new Node(8);
    root->left->right->right->right->right->right = new Node(9);
    int depth = maxDepth(root);  
    cout << depth ;  
    return 0;
}