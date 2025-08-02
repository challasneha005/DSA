//VERTICAL TRAVERSAL IN BINARY TREE  O(n log n) , O(2n)
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
vector <vector<int>> verticalTraversal(Node* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> todo;
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->data);
        if(node->left) 
            todo.push({node->left,{x-1,y+1}});
        if(node->right)
            todo.push({node->right,{x+1,y+1}});
    }
    vector<vector<int>> res;
    for(auto &i:nodes){
        vector<int> col;
        for(auto &j:i.second)
            col.insert(col.end(),j.second.begin(),j.second.end());
        res.push_back(col);
    }
    return res;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3); //treated as leaf 
    root->right->right = new Node(10);
    root->right->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    root->left->right->right->right->right = new Node(8);
    root->left->right->right->right->right->right = new Node(9);
    vector<vector<int>> result = verticalTraversal(root);
    cout << "Vertical Traversal of the Binary Tree:" << endl;
    for (const auto &col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}