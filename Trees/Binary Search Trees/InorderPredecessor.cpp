//INORDER  PREDECESSOR IN BST
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
Node* predecessorBrute(Node* root,Node* p){
    vector<Node*> inorderList;
    inorder(root,inorderList);
    for(int i=0;i<inorderList.size();i++){
        if(inorderList[i] == p){
            if(i-1 >=0 )
                return inorderList[i-1];
            else    
                return NULL;
        }
    }
    return NULL;
}
//better O(n) , O(1)-morris
Node* predecessorMorris(Node* root,Node *p){
    Node* cur = root;
    Node* prev =NULL;
    Node* pred = NULL;
    while(cur){
        if(!cur->left){
            if(cur == p)
                pred = prev;
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
                if (cur == p) 
                    pred = prev;
                prev = cur;
                cur = cur->right;
            }
        }
    }
    return pred;
}
//efficient O(h) , O(1)
Node* predecessorEfficient(Node* root,Node* p){
    Node* pred = NULL;
    while(root != NULL){
        if(p->data <= root->data)
            root = root->left;
        else{
            pred = root;
            root = root->right;
        }
    }
    return pred;
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
    // Node* next = predecessorBrute(root,p);
    // Node* next = predecessorMorris(root,p);
    Node* next = predecessorEfficient(root,p);
    cout << " predecessor: " << (next ? to_string(next->data) : "None") << "\n";
    return 0;
}