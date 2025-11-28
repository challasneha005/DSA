// CONVERT ARRAY TO LINKED LIST 
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* convertArrLL(vector<int> &a){
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1;i<a.size();i++){
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main(){
    vector<int> a={2,5,3,8};
    Node* head = convertArrLL(a);
    cout << head->data;
    return 0;
}
