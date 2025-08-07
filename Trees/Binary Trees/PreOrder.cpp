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
//RECURSIVE O(n) , O(n)
void preorderRecursive(Node* node){
    if(node == NULL)
        return ;
    cout << node->data << " ";
    preorderRecursive(node->left);
    preorderRecursive(node->right);
}
//ITERATIVE O(n) , O(n)
vector <int> preorderIterative(Node* root){
    vector <int> preorder;
    if(root == NULL)
        return preorder;
    stack <Node*> s;
    s.push(root);
    while(!s.empty()){
        root = s.top();
        s.pop();
        preorder.push_back(root->data);
        if(root->right != NULL)
            s.push(root->right);
        if(root->left != NULL)
            s.push(root->left);
    }
    return preorder;
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
    preorderRecursive(root);
    cout << endl;
    vector <int> preorder = preorderIterative(root);
    for(int i = 0; i < preorder.size(); i++)
    cout << preorder[i] << " ";
    return 0;
}
