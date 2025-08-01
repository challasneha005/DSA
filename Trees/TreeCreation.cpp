//TREE CREATION
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
Node* createTree() {
    int val;
    cout << "Enter value (-1 for NULL): ";
    cin >> val;
    if (val == -1)
        return NULL;
    Node* root = new Node(val);
    cout << "Enter left child of " << val << ":\n";
    root->left = createTree();
    cout << "Enter right child of " << val << ":\n";
    root->right = createTree();
    return root;
}
void inorder(Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = createTree();
    cout << "Inorder Traversal of Tree: ";
    inorder(root);
    cout << endl;
    return 0;
}
