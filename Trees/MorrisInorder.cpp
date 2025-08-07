//MORRIS INORDER O(n) , O(1)  
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
vector<int> getInorder(Node* root){
    vector<int> inorder;
    Node* cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return inorder;
}
void printInorder(Node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    
    vector <int> inorder = getInorder(root);
    for(int i=0;i<inorder.size();i++)
        cout << inorder[i] << " ";
    cout << endl;
    printInorder(root);
    return 0;
}