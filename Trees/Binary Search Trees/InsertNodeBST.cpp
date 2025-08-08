//INSERT A GIVEN NODE IN BINARY SEARCH TREE O(log n ) , O(h)
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
Node* insert(Node* root,int val){
    if(root == NULL)
        return new Node(val);
    Node* cur = root;
    while(true){
        if(cur->data <= val){
            if(cur->right !=NULL)
                cur= cur->right;
            else{
                cur->right = new Node(val);
                break;
            }
        }
        else{
            if(cur->left != NULL)
                cur = cur->left;
            else{
                cur->left= new Node(val);
                break;
            }
        }
    }
    return root;
}
void printInorder(Node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
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

    int val = 5;
    printInorder(root);
    cout << endl;
    insert(root, val);
    cout << "Inserted " << val << " into BST." << endl;
    printInorder(root);
    return 0;
}