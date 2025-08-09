//TWO SUM IN BINARY SEARCH TREE
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
//brute O(n)+O(n) , O(n)
void inorder(Node* root, vector<int>& arr) {
    if (!root) 
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
bool findTargetBrute(Node* root, int k) {
    vector<int> arr;
    inorder(root, arr);
    int l = 0, r = arr.size() - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == k) 
            return true;
        else if (sum < k) 
            l++;
        else 
            r--;
    }
    return false;
}
//better O(n) , O(h)*2

class BSTIterator{
    stack <Node*> s;
    bool reverse;
    void pushAll(Node* root){
    for(;root!=NULL;){
        s.push(root);
        if(reverse == true)
            root = root->right;
        else
            root = root->left;
    }
}
public:
    BSTIterator(Node* root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !s.empty();
    }
    int next(){
        Node* temp = s.top();
        s.pop();
        if(!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->data;
    }
};
bool findTarget(Node* root,int k){
    if(!root)
        return false;
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int i = l.next();
    int j = r.next();
    while(i<j){
        if(i+j == k)
            return true;
        else if(i+j < k)
            i = l.next();
        else
            j = r.next();
    }
    return false;
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

    cout << (findTargetBrute(root, 17) ? "Found\n" : "Not Found\n");
    cout << (findTarget(root, 17) ? "Found\n" : "Not Found\n");
    
    return 0;
}