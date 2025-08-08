//SEARCH IN BINARY SEARCH TREE O(log n -average) , n worst, O(h)
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
Node* search(Node* root,int val){
    while(root != NULL && root->data != val)
        root = (val<root->data) ? root->left:root->right;
    return root;
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

    int key = 7;
    Node* result = search(root, key);

    if (result)
        cout << "Found: " << result->data << endl;
    else
        cout << "Not Found" << endl;   
    return 0;
}
