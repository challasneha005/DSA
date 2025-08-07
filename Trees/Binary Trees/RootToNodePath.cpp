//ROOT TO NODE PATH BINARY TREE O(n) , O(h)
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
bool getPath(Node* root,vector<int> &a,int x){
    if(!root)
        return false;
    a.push_back(root->data);
    if(root->data == x)
        return true;
    if(getPath(root->left,a,x) || getPath(root->right,a,x))
        return true;
    a.pop_back();
    return false;
}
vector<int> pathRoottoNode(Node* root,int x){
    vector<int> a;
    if(root == NULL)
        return a;
    getPath(root,a,x);
    return a;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3); 
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left= new Node(6);
    root->left->right->right = new Node(7);
    int x = 7;
    vector<int> path = pathRoottoNode(root,x);
    for(auto it:path)
        cout << it << " ";
    return 0;
}
