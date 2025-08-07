//TOP VIEW OF BINARY TREE  O(n) , O(n)
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
vector<int> topview(Node* root){
    vector <int> ans;
    if(root==NULL)
        return ans;
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int line = it.second;
        if(m.find(line)==m.end())
            m[line] = node->data;
        if(node->left != NULL)
            q.push({node->left,line-1});
        if(node->right != NULL)
            q.push({node->right,line+1});
    }
    for (auto it: m)
        ans.push_back(it.second);
    return ans;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right = new Node(3); //treated as leaf 
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> result = topview(root);
    cout << "Top view of the binary tree is: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;
    return 0;
}
