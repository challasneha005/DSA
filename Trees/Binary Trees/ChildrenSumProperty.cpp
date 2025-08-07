//CHILDREN SUM PROPERTY IN BINARY TREE O(n) , O(n)
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
void changeTree(Node* root ){
    if(root == NULL)
        return;
    int child = 0;
    if(root->left)
        child += root->left->data;
    if(root->right)
        child += root->right->data;
    if(child>=root->data)
        root->data = child;
    else{
        if(root->left)
            root->left->data = root->data;
        if(root->right)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if(root->left)
        tot += root->left->data;
    if(root->right)
        tot += root->right->data;
    if(root->left or root->right)
        root->data = tot;
}
void inorder(Node* node){
    if(node == NULL)
        return ;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout << "Before change: ";
    inorder(root);
    cout << endl;

    changeTree(root);

    cout << "After change: ";
    inorder(root);
    cout << endl;
    return 0;
}
