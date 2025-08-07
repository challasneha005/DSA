//ALL TRAVERSALS O(3n) , O(4n)
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
void preInPostOrderTraversals(Node* root){
    stack <pair<Node*,int>> s;
    vector <int> pre,in,post;
    s.push({root,1});
    if(root == NULL)
        return;
    while (!s.empty()){
        auto it = s.top();
        s.pop();
        //preorder increase to 2,left side children
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->left != NULL)
                s.push({it.first->left,1});
        }
        //inorder increase to 3,right side children
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if(it.first->right != NULL)
                s.push({it.first->right,1});
        }
        //postorder don't push
        else
            post.push_back(it.first->data);
    }
    cout << "Preorder: ";
    for (int val : pre) 
        cout << val << " ";
    cout << "\nInorder: ";
    for (int val : in) 
        cout << val << " ";
    cout << "\nPostorder: ";
    for (int val : post) 
        cout << val << " ";
    cout << endl;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    root->left->right->right->right->right = new Node(8);
    root->left->right->right->right->right->right = new Node(9);
    preInPostOrderTraversals(root);    
    return 0;
}
