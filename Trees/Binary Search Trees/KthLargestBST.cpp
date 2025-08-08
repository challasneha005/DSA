//Kth LARGEST ELEMENT IN BINARY SEARCH TREE O(n) , O(h)
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
int totalNodes(Node* root) {
    if (!root) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}
//reverse right and left tarversals then O(h+k)
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
int kthLargest(Node* root,int k){
    int n = totalNodes(root);
    int target = n-k+1;
    int count = 0;
    int ans = -1;
    inorder(root,count,target,ans);
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
    int result = kthLargest(root, val);
    cout << "kth Largest element: " << result << endl;
    return 0;
}