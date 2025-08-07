//LEVEL ORDER TRAVERSAL O(n) , O(n)
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
vector <vector<int>> levelOrder(Node* root){
    vector <vector<int>> ans;
    if(root == NULL)
        return ans;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> level;
        for(int i = 0; i < n; i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
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
    vector<vector<int>> result = levelOrder(root);
    for (const auto& level : result) {
        for (int val : level)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
