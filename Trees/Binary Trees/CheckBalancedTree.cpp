//CHECK FOR BALANCED BINARY TREE  
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
//NAIVE O(n*n)
int findHeight(Node* root) {
    if (root == NULL)
        return 0;
    int left = findHeight(root->left);
    int right = findHeight(root->right);
    return 1 + max(left,right);
}
bool checkNaive(Node* root){
    if(root==NULL)
        return true;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    if(abs(lh-rh)>1)
    return false;
    bool left = checkNaive(root->left);
    bool right = checkNaive(root->right);
    if(!left || !right)
        return false;
    return false;
}
//using height only  O(n) , O(n)
int height(Node* root){
    if(root==NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    if(lh == -1)
        return -1;
    if(rh == -1)
        return -1;
    if(abs(lh - rh) >1)
        return -1;
    return max(lh,rh)+1;
}
bool check(Node* root){
    return height(root) != -1;
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
    // bool balance = checkNaive(root);
    bool balance = check(root) ;
    if (balance)
        cout << "The tree is balanced." << endl;
    else
        cout << "The tree is NOT balanced." << endl;
    return 0;
}
