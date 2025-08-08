//LOWEST COMMON FACTOR BINARY SEARCH TREE 
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
//Naive O(n) , O(n) same as binary tree
Node* lowestCommonAncestorNaive(Node* root,Node* p,Node* q){
    if(root==NULL || root==p || root==q)
        return root;
    Node* left = lowestCommonAncestorNaive(root->left,p,q);
    Node* right = lowestCommonAncestorNaive(root->right,p,q);
    if(left == NULL)
        return right;
    else if(right == NULL)
        return left;
    else
        return root;
}
//efficient O(h) , O(1)
Node* lowestCommonAncestor(Node* root,Node* p,Node* q){
    if(root == NULL)
        return NULL;
    int cur = root->data;
    if(cur < p->data && cur < q->data)
        return lowestCommonAncestor(root->right,p,q);
    if(cur > p->data && cur > q->data )
        return lowestCommonAncestor(root->left,p,q);
    return root;
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

    // Let's find LCA of node 4 and node 7
    Node* p = root->left->right->left;  // Node with value 4
    Node* q = root->left->right->right; // Node with value 7

    // Node* lca = lowestCommonAncestorNaive(root, p, q);
    Node* lca = lowestCommonAncestor(root, p, q);
    if (lca)
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lca->data << endl;
    else
        cout << "No Common Ancestor Found." << endl;

    return 0;
}