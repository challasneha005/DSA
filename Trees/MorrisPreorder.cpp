//MORRIS PREORDER O(n) , O(1)  
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
vector<int> getPreorder(Node* root){
    vector<int> preorder;
    Node* cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            Node* prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;
            if(prev->right == NULL){
                preorder.push_back(cur->data);
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}
void printPreorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
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
    
    vector <int> preorder = getPreorder(root);
    for(int i=0;i<preorder.size();i++)
        cout << preorder[i] << " ";
    cout << endl;
    printPreorder(root);
    return 0;
}