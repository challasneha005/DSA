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
void inorderRecursive(Node* node){
    if(node == NULL)
        return ;
    inorderRecursive(node->left);
    cout << node->data << " ";
    inorderRecursive(node->right);
}
//ITERATIVE O(n) , O(n) 
vector <int> inorderIterative(Node* root){
    vector <int> inorder;
    stack <Node*> s;
    Node* node = root;
    while(true){
        if(node!= NULL){
            s.push(node);
            node = node->left;
        }
        else{
            if(s.empty() == true)
                break;
            node = s.top();
            s.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
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
    inorderRecursive(root);
    cout << endl;
    vector <int> inorder = inorderIterative(root);
    for(int i = 0; i < inorder.size(); i++)
    cout << inorder[i] << " ";
    return 0;
}
