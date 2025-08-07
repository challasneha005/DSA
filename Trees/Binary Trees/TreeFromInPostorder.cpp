//TREE FROM INORDER AND POSTORDER O(n)+log n-(hash) , O(n)
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
Node* buildTree(vector <int> &inorder,int inStart,int inEnd, 
    vector <int> postorder,int postStart,int postEnd,map<int,int> &m){
        if(inStart > inEnd || postStart > postEnd)
            return NULL;
        Node* root = new Node(postorder[postEnd]);
        int inRoot = m[postorder[postEnd]];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(inorder,inStart,inRoot-1,
                postorder,postStart,postStart+numsLeft-1,m);
        root->right = buildTree(inorder,inRoot+1,inEnd,
                postorder,postStart+numsLeft,postEnd-1,m);   
        return root;     
    }
Node* build(vector <int> &inorder,vector<int> &postorder){
    map <int,int> m;
    if(inorder.size() != postorder.size())
        return NULL;
    for(int i=0;i<inorder.size();i++)
        m[inorder[i]] = i;
    Node* root = buildTree(inorder,0,inorder.size()-1,
                    postorder,0,postorder.size()-1,m);
    return root;
}
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = { 9, 15, 7, 20, 3};
    Node* root = build(inorder,postorder);
    cout << "Inorder of constructed tree: ";
    printInorder(root); // should print 9 3 15 20 7
    cout << endl;
    return 0;
}
