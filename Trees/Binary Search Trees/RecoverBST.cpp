//RECOVER BST FROM SWAPPED TWO NODES
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
//brute O(2n + n log n) , O(n)
void storeInorder(Node* root, vector<Node*>& arr) {
    if (!root) 
        return;
    storeInorder(root->left, arr);
    arr.push_back(root);
    storeInorder(root->right, arr);
}
void recoverTreeBrute(Node* root) {
    vector<Node*> arr;
    storeInorder(root, arr);
    Node *first = NULL, *second = NULL;
    for (int i = 0; i < (int)arr.size() - 1; i++) {
        if (arr[i]->data > arr[i + 1]->data) {
            if (!first) {
                first = arr[i];
                second = arr[i + 1];
            } 
            else {
                second = arr[i + 1];
                break;
            }
        }
    }
    if (first && second) 
        swap(first->data, second->data);
}
void inorderPrint(Node* root) {
    if (!root) 
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
//better O(n) , O(h)   -- O(1) -morris for inorder
Node* first = NULL ,*middle = NULL, *last = NULL;
Node* prevNode = new Node(INT_MIN);
void inorder(Node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    if(prevNode != NULL && (root->data < prevNode->data)){
        if(first == NULL){
            first = prevNode;
            middle = root;
        }
    else
        last = root;
    }
    prevNode = root;
    inorder(root->right);
}
void recoverTree(Node* root){
    first = middle = last = NULL;
    prevNode = new Node(INT_MIN);
    inorder(root);
    if(first && last)
        swap(first->data,last->data);
    else if(first && middle)
        swap(first->data,middle->data);
}
int main() {
    Node* root = new Node(8);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right->right->left = new Node(13);

    cout << "Before recovery: ";
    inorderPrint(root); cout << "\n";

    // recoverTreeBrute(root);
    recoverTree(root);

    cout << "After recovery: ";
    inorderPrint(root); cout << "\n";
    return 0;
}