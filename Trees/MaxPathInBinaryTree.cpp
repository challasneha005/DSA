//MAXIMUM PATH SUM IN BINARY TREE   O(n) , O(h)
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
int maxPathDown(Node* root,int &maxi){
    if(root==NULL)
        return 0;
    int leftsum = max(0,maxPathDown(root->left,maxi)); //ignores negatives
    int rightsum = max(0,maxPathDown(root->right,maxi));
    maxi = max(maxi,leftsum+rightsum+root->data);
    // return max(root->data,max(leftsum+root->data,rightsum+root->data));
    return root->data + max(leftsum, rightsum);
}
int maxPath(Node* root){
    int maxi = INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
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
    int maxPathSum = maxPath(root);
    cout << "Max path sum is : " << maxPathSum;
    return 0;
}