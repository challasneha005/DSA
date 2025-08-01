//ZIG-ZAG OR SPIRAL TRAVERSAL  O(n) , O(n)
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
vector <vector<int>> zigzag(Node* root){
    vector <vector<int>> result;
    if(root == NULL)
        return result;
    queue <Node*> q;
    q.push(root);
    bool lefttoRight = true;
    while(!q.empty()){
        int n = q.size();
        vector<int> level(n);
        for(int i = 0; i < n; i++){
            Node* node = q.front();
            q.pop();
            //position to fill nodes's value
            int index = (lefttoRight) ? i:(n-1-i);
            level[index] = node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        //after level
        lefttoRight = !lefttoRight;
        result.push_back(level);
    }
    return result;
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
    vector<vector<int>> result = zigzag(root);
    cout << "Zigzag Level Order Traversal:\n";
    for (auto &level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}