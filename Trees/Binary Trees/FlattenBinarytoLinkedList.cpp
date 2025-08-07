//FLATTEN A BINARY TREE TO LINKED LIST
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
//RECURSIVE O(n) , O(h=n)
void flatten(Node* root,Node* &prev){
    if(root == NULL)
        return ;
    flatten(root->right,prev);
    flatten(root->left,prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}
void flattenRecursive(Node* root){
    Node* prev = NULL;
    flatten(root,prev);
}
//STACK O(n) , O(n)
void flattenStack(Node* root){
    stack <Node*> s;
    s.push(root);
    while(!s.empty()){
        Node * cur = s.top();
        s.pop();
        if(cur->right)
            s.push(cur->right);
        if(cur->left)
            s.push(cur->left);
        if(!s.empty())
            cur->right=s.top();
        cur->left = NULL;
    }
}
//MORRIS-LIKE(NO STACK/RECURSION) O(n) , O(1)
void flattenMorris(Node* root){
    Node* cur = root;
    while(cur != NULL){
        if(cur->left != NULL){
            Node* prev = cur->left;
            while(prev->right)
                prev = prev->right;
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
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
    // flattenRecursive(root); 
    // flattenStack(root); 
    flattenMorris(root);

    Node* temp = root;
    while(temp){
        cout << temp->data << " ";
        temp = temp->right;
    }
        
    return 0;
}
