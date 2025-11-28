// CREATE ARR TO DLL
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node * back;

    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* convertArrDLL(vector<int> a){
    Node* head = new Node(a[0]);
    Node* prev = head;
    for(int i=1;i<a.size();i++){
        Node* temp = new Node (a[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
int main(){
    vector<int> a={2,5,3,8};
    Node* head = convertArrDLL(a);
    cout << head->data;
    return 0;
}
