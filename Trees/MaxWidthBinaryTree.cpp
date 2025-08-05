//MAXIMUM WIDTH OF A  BINARY TREE O(n) , O(n)
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
int maxWidth(Node* root){
    if(!root)
        return 0;
    int ans = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        int n = q.size();
        int mini = q.front().second;
        int first,last;
        for(int i = 0; i < n; i++){
            int cur_id = q.front().second-mini;
            Node* node = q.front().first;
            q.pop();
            if(i==0)
            first = cur_id;
            if(i==n-1)
            last = cur_id;
            if(node->left)
            q.push({node->left, 2*cur_id+1});
            if(node->right)
            q.push({node->right, 2*cur_id+2});
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    int width = maxWidth(root);
    cout << "Maximum width of the binary tree is " << width;
    return 0;
}