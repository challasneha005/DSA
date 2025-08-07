//BOUNDARY TRAVERSAL IN BINARY TREE  O(h)+O(h)+O(n) , O(n)
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
//ANTI-CLOCK WISE
bool isLeaf(Node* node) {
    return node!=NULL && node->left==NULL && node->right==NULL;
}
void addLeftAntiClock(Node* root,vector<int> &res){
    Node* cur = root->left;
    while(cur){
        if(!isLeaf(cur))
            res.push_back(cur->data);
        if(cur->left)
            cur = cur->left;
        else    
            cur = cur->right;
    }
}
void addRightAntiClock(Node* root,vector<int> &res){
    Node* cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur))
            temp.push_back(cur->data);
        if(cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for(int i=temp.size()-1;i>=0;--i)
        res.push_back(temp[i]);
}
void addLeafAntiClock(Node* root,vector<int> &res){
    if (!root) 
        return;
    if(isLeaf(root)){
        cout << "Leaf: " << root->data << endl;  // Add this line
        res.push_back(root->data);
        return;
    }
    if(root->left)
        addLeafAntiClock(root->left,res);
    if(root->right)
        addLeafAntiClock(root->right,res);
}
vector <int> printBoundaryAntiClock(Node* root){
    vector<int> res;
    if(!root)
        return res;
    if(!isLeaf(root))
        res.push_back(root->data);
    addLeftAntiClock(root,res);
    addLeafAntiClock(root,res);
    addRightAntiClock(root,res);
    return res;
}

//CLOCK WISE
void addRightClock(Node* root, vector<int>& res) {
    Node* cur = root->right;
    while (cur) {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
}
void addLeftClock(Node* root, vector<int>& res) {
    Node* cur = root->left;
    vector<int> temp;
    while (cur) {
        if (!isLeaf(cur))
            temp.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
    reverse(temp.begin(), temp.end());
    for (int val : temp)
        res.push_back(val);
}
void addLeafClock(Node* root, vector<int>& res) {
    if (!root) return;
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    addLeafClock(root->right, res);
    addLeafClock(root->left, res);
}
vector <int> printBoundaryClockwise(Node* root) {
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addRightClock(root, res);        
    addLeafClock(root, res);         
    addLeftClock(root, res);  
    return res;
}
int main() {
     Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->left = new Node(10);

    vector<int> res = printBoundaryAntiClock(root);
    cout << "Boundary traversal (anti-clockwise): ";
    for (int val : res)
        cout << val << " ";
    cout << endl;

    vector<int> clock = printBoundaryClockwise(root);
    cout << "Boundary traversal (clockwise): ";
    for (int val : clock)
        cout << val << " ";
    cout << endl;
    return 0;
}
