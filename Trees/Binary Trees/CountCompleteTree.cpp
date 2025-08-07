//COUNT COMPLETE TREE NODES 
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
//brute O(n) , O(h)
void inorder(Node* node, int &cnt){
    if(node == NULL)
        return ;
    inorder(node->left,cnt);
    cout << node->data << " ";
    cnt++; 
    inorder(node->right,cnt);
}
int countCompleteNodes(Node* root) {
    int cnt  = 0;
    inorder(root,cnt);
    return cnt;
}
// O(log n* log n) , O(log n)
int findHeightLeft(Node* n){
    int height = 0;
    while(n){
        height++;
        n = n->left;
    }
    return height;
}
int findHeightRight(Node* n){
    int height = 0;
    while(n){
        height++;
        n = n->right;
    }
    return height;
}
int countNodes(Node* root){
    if(root == NULL)
        return 0;
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);
    if(lh == rh)
        return (1<<lh)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    int cnt = countCompleteNodes(root);
    // int count = countNodes(root);
    cout << "No.of nodes in complete tree: "<< cnt ;
    return 0;
}
