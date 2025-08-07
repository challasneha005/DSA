//DIAMETER OF A BINARY TREE  
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
int maxDiameterNaive(Node* root){
    if(root==NULL)
        return true;
    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    int maxi =  lh+rh;
    int left = maxDiameterNaive(root->left);
    int right = maxDiameterNaive(root->right);
    return max({maxi,left,right});
}
//using height only  O(n) , O(n)
int maxDiameter(Node* root,int &maxi){
    if(root == NULL)  
        return 0;
    int lh = maxDiameter(root->left,maxi);
    int rh = maxDiameter(root->right,maxi);
    maxi = max(maxi,lh+rh);
    return 1+ max(lh,rh);
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
    // int diameter = maxDiameterNaive(root);
    int maxi = 0;
    int diameter = maxDiameter(root,maxi);
    cout << "Diameter of the binary tree is: " << diameter << endl;
    return 0;
}
