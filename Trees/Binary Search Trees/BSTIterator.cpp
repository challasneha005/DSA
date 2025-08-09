 //BST ITERATION
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
//brute O(1) O(n)
class BSTIteratorBrute {
    vector<int> inorderVals;
    int index;
    void inorder(Node* root) {
        if (!root) 
            return;
        inorder(root->left);
        inorderVals.push_back(root->data);
        inorder(root->right);
    }
public:
    BSTIteratorBrute(Node* root) {
        inorder(root);
        index = 0;
    }
    bool hasNext() {
        return index < (int)inorderVals.size();
    }
    int next() {
        return inorderVals[index++];
    }
};
//efficient O(1) , O(h)
class BSTIterator{
    stack <Node*> s;
    void pushAll(Node* root){
    for(;root!=NULL;){
        s.push(root);
        root = root->left;
    }
}
public:
    BSTIterator(Node* root){
        pushAll(root);
    }
    bool hasNext(){
        return !s.empty();
    }
    int next(){
        Node* temp = s.top();
        s.pop();
        pushAll(temp->right);
        return temp->data;
    }
};
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
    
    // BSTIteratorBrute it(root);
    BSTIterator it(root);
    while (it.hasNext()) {
        cout << it.next() << " ";
    }
    cout << "\n";
      
    return 0;
}
