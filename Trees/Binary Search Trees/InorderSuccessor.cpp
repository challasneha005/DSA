//INORDER SUCCESSOR IN BST
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
//brute O(n + log n) , O(n)
void inorder(Node* root,vector<Node*> &inorderList){
    if(!root)
        return;
    inorder(root->left,inorderList);
    inorderList.push_back(root);
    inorder(root->right,inorderList);

}
Node* successorBrute(Node* root,Node* p){
    vector<Node*> inorderList;
    inorder(root,inorderList);
    for(int i=0;i<inorderList.size();i++){
        if(inorderList[i] == p){
            if(i+1 < inorderList.size())
                return inorderList[i+1];
            else    
                return NULL;
        }
    }
    return NULL;
}
//better O(n) , O(1)-morris
Node* successorMorris(Node* root,Node *p){
    Node* cur = root;
    Node* prev =NULL;
    Node* s = NULL;
    while(cur){
        if(!cur->left){
            if(prev == p)
                s = cur;
            prev = cur;
            cur = cur->right;
        }
        else{
            Node* temp = cur->left;
            while (temp->right && temp->right != cur) 
                temp = temp->right;
            if (!temp->right) {
                temp->right = cur;
                cur = cur->left;
            } 
            else {
                temp->right = NULL;
                if (prev == p) 
                    s = cur;
                prev = cur;
                cur = cur->right;
            }
        }
    }
    return s;
}
//efficient O(h) , O(1)
Node* successorEfficient(Node* root,Node* p){
    Node* s = NULL;
    while(root != NULL){
        if(p->data >= root->data)
            root = root->right;
        else{
            s = root;
            root = root->left;
        }
    }
    return s;
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

    Node* p = root->left->right->left;  // Node with value 4
    Node* next = successorBrute(root,p);
    // Node* next = successorMorris(root,p);
    // Node* next = successorEfficient(root,p);
    cout << " successor: " << (next ? to_string(next->data) : "None") << "\n";
    return 0;
}
