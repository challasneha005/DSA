//PRINT ALL NODES AT A DISTANCE OF K IN BINARY TREE O(2n) , O(3n)
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
void markParents(Node* root,unordered_map <Node*,Node*> & parentTrack,Node* target){
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left){
            parentTrack[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parentTrack[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
vector <int> distancek(Node* root,Node* target,int k){
    unordered_map <Node*,Node*> parentTrack;
    markParents(root,parentTrack,target);
    unordered_map <Node*,bool> visited;
    queue <Node*> q;
    q.push(target);
    visited[target] = true;
    int curLevel = 0;
    while(!q.empty()){
        int n = q.size();
        if(curLevel++ == k)
            break;
        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parentTrack[curr] && !visited[parentTrack[curr]]){
                q.push(parentTrack[curr]);
                visited[parentTrack[curr]] = true;
            }
        }
    }
    vector <int> res;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        res.push_back(curr->data);
    }
    return res;
}
Node* findTarget(Node* root, int val) {
    if (!root) 
        return NULL;
    if (root->data == val) 
        return root;
    Node* left = findTarget(root->left, val);
    if (left) 
        return left;
    return findTarget(root->right, val);
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
    
    int target,k;
    cin >> target >> k;
    Node* targetsearch = findTarget(root, target);
    if (target == NULL) {
        cout << "Target node not found.\n";
        return 0;
    }
    vector <int> res = distancek(root,targetsearch,k);
    for (int val : res)
        cout << val << " ";
    cout << endl;
    return 0;
}