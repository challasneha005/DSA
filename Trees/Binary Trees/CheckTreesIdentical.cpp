//CHECK TWO TREES ARE IDENTICAL OR NOT  O(n) , O(n)
//do traversals and check same or not also can be done
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
bool isSame(Node* p,Node* q){
    if(p==NULL && q==NULL)
        return p==q;
    return (p->data == q->data) && isSame(p->left,q->left) && isSame(p->right,q->right);
}
int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    if (isSame(root1, root2))
        cout << "The trees are identical." << endl;
    else
        cout << "The trees are NOT identical." << endl;
    return 0;
}
