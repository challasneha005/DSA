//TREE FROM INORDER AND PREORDER O(n) , O(n)
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
Node* buildTree(vector <int> &preorder,int PreStart,int preEnd, 
    vector <int> inorder,int inStart,int inEnd,map<int,int> &m){
        if(PreStart > preEnd || inStart > inEnd)
            return NULL;
        Node* root = new Node(preorder[PreStart]);
        int inRoot = m[root->data];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder,PreStart+1,PreStart+numsLeft,
                inorder,inStart,inRoot-1,m);
        root->right = buildTree(preorder,PreStart+numsLeft+1,preEnd,
                inorder,inRoot+1,inEnd,m);   
        return root;     
    }
Node* build(vector <int> &preorder,vector<int> &inorder){
    map <int,int> m;
    for(int i=0;i<inorder.size();i++)
        m[inorder[i]] = i;
    Node* root = buildTree(preorder,0,preorder.size()-1,
                    inorder,0,inorder.size()-1,m);
    return root;
}
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    Node* root = build(preorder, inorder);
    cout << "Inorder of constructed tree: ";
    printInorder(root); // should print 9 3 15 20 7
    cout << endl;
    return 0;
}