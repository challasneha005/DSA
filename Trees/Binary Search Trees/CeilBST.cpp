//CEIL IN BINARY SEARCH TREE O(log n -average) , n worst, O(h)
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
int findCeil(Node* root,int key){
    int ceil = -1;
    while(root){
        if(root->data == key){
            ceil = root->data;
            return ceil;
        }
        if(key>root->data)
            root = root->right;
        else{
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
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

    int key = 8;
    int result = findCeil(root, key);

    if (result != -1)
        cout << "Ceil: " << result << endl;
    else
        cout << "Ceil does not exist" << endl;   
    return 0;
}