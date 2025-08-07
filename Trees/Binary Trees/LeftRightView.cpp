//LEFT ,RIGHT VIEW OF BINARY TREE  O(n) , O(n)
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
//Recursive preorder O(n) , O(n)
void recursionRight(Node* root,int level,vector<int> &res){
    if(root==NULL)
        return;
    if(res.size()==level)
        res.push_back(root->data);
    recursionRight(root->right,level+1,res);
    recursionRight(root->left,level+1,res);
}
vector <int> rightview(Node* root){
    vector<int> res;
    recursionRight(root,0,res);
    return res;
}
void recursionLeft(Node* root,int level,vector<int> &res){
    if(root==NULL)
        return;
    if(res.size()==level)
        res.push_back(root->data);
    recursionLeft(root->left,level+1,res);
    recursionLeft(root->right,level+1,res);
}
vector<int> leftview(Node* root){
    vector <int> res;
    recursionLeft(root,0,res);
    return res;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right = new Node(3); //treated as leaf 
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> left = leftview(root);
    vector<int> right = rightview(root);
    cout << "Left view of the binary tree is: ";
    for (int val : left)
        cout << val << " ";
    cout << endl;
    cout << "Right view of the binary tree is: ";
    for (int val : right)
        cout << val << " ";
    cout << endl;
    return 0;
}
