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
//RECURSIVE O(n) , O(n)
void postorderRecursive(Node* node){
    if(node == NULL)
        return ;
    postorderRecursive(node->left);
    postorderRecursive(node->right);
    cout << node->data << " ";
}
//ITERATIVE 
//USING 2 STACKS O(n) , O(2n)
vector <int> postorderIterativeTwoStacks(Node* root){
    vector <int> postorder;
    stack <Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        s2.push(root);
        if(root->left != NULL)
            s1.push(root->left);
        if(root->right != NULL)
            s1.push(root->right);
    }
    while(!s2.empty()){
        postorder.push_back(s2.top()->data);
        s2.pop();
    }
    return postorder;
}
//USING 1 STACK O(2n) , O(n)
vector <int> postorderIterativeOneStack(Node* root){
    vector <int> postorder;
    if (root == NULL)
        return postorder;
    stack<Node*> s;
    Node* cur = root;
    Node* temp = nullptr;
    while(cur != NULL || !s.empty()){
        if(cur != NULL){
            s.push(cur);
            cur = cur->left;
        }
        else{
            temp = s.top()->right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                postorder.push_back(temp->data);
                 // Backtrack while node is right child of stack's top
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                cur = temp;
            }
        }
    }
    return postorder;
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
    postorderRecursive(root);
    cout << endl;
    //usingtwo stacks
    vector <int> postorder2 = postorderIterativeTwoStacks(root);
    for(int i = 0; i < postorder2.size(); i++)
    cout << postorder2[i] << " ";
    cout << endl;
    //using one stack
    vector <int> postorder1 = postorderIterativeOneStack(root);
    for(int i = 0; i < postorder1.size(); i++)
    cout << postorder1[i] << " ";
    cout << endl;
    return 0;
}
