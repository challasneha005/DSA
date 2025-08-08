//CONSTRUCT BINARY SEARCH TREE FROM PREORDER TRAVERSAL
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
//Naive O(n*n)
Node* insertBSTNaive(Node* root, int key) {
    if (root == NULL)
        return new Node(key);
    if (key < root->data)
        root->left = insertBSTNaive(root->left, key);
    else
        root->right = insertBSTNaive(root->right, key);
    return root;
}
Node* bstFromPreorderNaive(vector<int>& preorder) {
    if (preorder.empty()) 
        return NULL;
    Node* root = new Node(preorder[0]); // First element as root
    for (int i = 1; i < preorder.size(); i++)
        root = insertBSTNaive(root, preorder[i]);
    return root;
}
//Better O(n log n+n) , O(n)
Node* buildTreeBetter(vector<int> &preorder, int preStart, int preEnd,
                vector<int> &inorder, int inStart, int inEnd,
                unordered_map<int, int> &m) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    Node* root = new Node(preorder[preStart]); // First element is root
    int inRoot = m[root->data];                // Root index in inorder
    int numsLeft = inRoot - inStart;           // Elements in left subtree
    root->left = buildTreeBetter(preorder, preStart + 1, preStart + numsLeft,
                           inorder, inStart, inRoot - 1, m);
    root->right = buildTreeBetter(preorder, preStart + numsLeft + 1, preEnd,
                            inorder, inRoot + 1, inEnd, m);
    return root;
}
Node* bstFromPreorderBetter(vector<int> &preorder) {
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
        m[inorder[i]] = i;
    return buildTreeBetter(preorder, 0, preorder.size() - 1,
                     inorder, 0, inorder.size() - 1, m);
}
//USING RANGE
Node* build(vector<int> &preorder,int &i,int bound){
    if(i==preorder.size() || preorder[i] > bound)
        return NULL;
    Node* root = new Node(preorder[i++]);
    root->left = build(preorder,i,root->data);
    root->right = build(preorder,i,bound);
    return root;
}
Node* bstFromPreorder(vector<int> & preorder){
    int i=0;
    return build(preorder,i,INT_MAX);
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    // Node* root = bstFromPreorderNaive(preorder);
    // Node* root = bstFromPreorderBetter(preorder);
    Node* root = bstFromPreorder(preorder);
    cout << "Inorder Traversal of Constructed BST: ";
    inorder(root);
    cout << endl;
    return 0;
}