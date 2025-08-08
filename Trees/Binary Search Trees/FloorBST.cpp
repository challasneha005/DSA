//FLOOR IN BINARY SEARCH TREE O(log n -average) , n worst, O(h)
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
int findFloor(Node* root,int key){
    int floor = -1;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(key>root->data){
            floor = root->data;
            root = root->right;
        }
        else
            root = root->left;
    }
    return floor;
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

    int key = 5;
    int result = findFloor(root, key);

    if (result != -1)
        cout << "Floor: " << result << endl;
    else
        cout << "Floor does not exist" << endl;   
    return 0;
}