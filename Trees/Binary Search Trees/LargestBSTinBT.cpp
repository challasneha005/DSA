//LARGEST BST IN A BT
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
//brute O(n*n)
bool isBST(Node* root, long minVal, long maxVal) {
    if (!root) 
        return true;
    if (root->data <= minVal || root->data >= maxVal) 
        return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}
int countNodes(Node* root) {
    if (!root) 
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int largestBST(Node* root) {
    if (!root) 
        return 0;
    if (isBST(root, LONG_MIN, LONG_MAX)) 
        return countNodes(root);
    return max(largestBST(root->left), largestBST(root->right));
}
//better O(n) ,O(1)-morris
struct NodeValue{
    int minNode;
    int maxNode;
    int maxSize;
    NodeValue(int minNode,int maxNode,int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
NodeValue largestBSThelp(Node* root){
    if(!root)
        return NodeValue(INT_MAX,INT_MIN,0);
    auto left = largestBSThelp(root->left);
    auto right = largestBSThelp(root->right);
    if(left.maxNode < root->data && root->data < right.minNode)
        return NodeValue(min(root->data,left.minNode) ,
                         max(root->data,right.maxNode),
                         left.maxSize+right.maxSize+1);
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}
int largeBSTsubtree(Node* root){
    return largestBSThelp(root).maxSize;
}
int main() {
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    cout << "Largest BST size: " << largestBST(root) << endl;
    cout << "Largest BST size: " << largeBSTsubtree(root) << endl;

    return 0;
}