//Kth SMALLEST ELEMENT IN BINARY SEARCH TREE O(h+k) , O(h)
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
void inorder(Node* root,int &count,int k,int & ans){
    if(root == NULL)
        return;
    inorder(root->left, count, k, ans);
    count++;
    if (count == k) {
        ans = root->data;
        return;
    }
    inorder(root->right,count,k,ans);
}
int kthSmallest(Node* root,int k){
    int count = 0;
    int ans = -1;
    inorder(root,count,k,ans);
    return ans;
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

    int val = 3;
    int result = kthSmallest(root, val);
    cout << "kth Smallest element: " << result << endl;
    return 0;
}