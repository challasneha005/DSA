//SERIALIZE AND DESERIALIZE O(n) , O(n) for both
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
//ENCODE
string serialize(Node* root){
    if(!root)
        return " ";
    string s = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        if(cur == NULL)
            s.append("#,");
        else
            s.append(to_string(cur->data)+",");
        if(cur != NULL){
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    cout << s;
    return s;
}
//DECODE
Node* deserialize(string data){
    if(data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node* root = new Node(stoi(str));
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        getline(s,str,',');
        if(str == "#")
            node->left = NULL;
        else{
            Node* leftNode = new Node(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str == "#")
            node->right = NULL;
        else{
            Node* rightNode = new Node(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    
    string serialized = serialize(root);
    cout << "Serialized Tree: " << serialized << endl;
 
    Node* newRoot = deserialize(serialized);
    cout << "Inorder of Deserialized Tree: ";
    inorder(newRoot); // Should match original inorder
    cout << endl;
    return 0;
}