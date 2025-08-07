//MIN TIME TAKEN TO BURN A BINARY TREE FROM A NODE O(2n) , O(n)
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
Node* bfstoMapParents(Node* root,map<Node* , Node*>  &m,int start){
    queue <Node*> q;
    q.push(root);
    Node* res;
    while(!q.empty()){
        Node* node = q.front();
        q.pop();    
        if(node->data == start)
            res = node;
        if(node->left){
            m[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            m[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}
int findMaxDist(map <Node*,Node*> &m,Node* target ){
    map<Node*,bool> vis;
    queue <Node*> q;
    q.push(target);
    vis[target] = 1;
    int maxi = 0;
    while(!q.empty()){
        int n = q.size();
        int fl = 0;
        for(int i = 0;i<n;i++){
            auto node = q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !vis[node->right]){
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }
            if(m[node] && !vis[m[node]]){
                fl = 1;
                vis[m[node]] = 1;
                q.push(m[node]);
            }
        }
        if(fl)
            maxi++;
    }
    return maxi;
}
int minTimeToBurn(Node* root, int start) {
    map<Node*, Node*> m;
    Node* target = bfstoMapParents(root,m,start);
    int maxi = findMaxDist(m,target);
    return maxi;
}
int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);

    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(9);
      int start = 5;
    cout << "Minimum time to burn tree from node " << start << ": "
         << minTimeToBurn(root, start) << endl;
    return 0;
}
