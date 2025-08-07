//MORRIS POSTORDER O(n) , O(1)
//modified reverse preorder (Root → Right → Left) and then reversing the result.  
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
vector<int> getPostorder(Node* root){
    vector<int> postorder;
    Node* cur = root;
    while(cur != NULL){
        if(cur->right == NULL){
            postorder.push_back(cur->data);
            cur = cur->left;
        }
        else{
            Node* prev = cur->right;
            while(prev->left && prev->left != cur)
                prev = prev->left;
            if(prev->left == NULL){
                postorder.push_back(cur->data);
                prev->left = cur;
                cur = cur->right;
            }
            else{
                prev->left = NULL;
                cur = cur->left;
            }
        }
    }
    reverse(postorder.begin(), postorder.end());
    return postorder;
}
void printPostorder(Node* root) {
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    
    vector <int> postorder = getPostorder(root);
    for(int i=0;i<postorder.size();i++)
        cout << postorder[i] << " ";
    cout << endl;
    printPostorder(root);
    return 0;
}
