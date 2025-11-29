// REVERSE DLL
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
Node* createDLL() {
    int x;
    cin >> x;
    if (x == -1) 
        return nullptr;
    Node* head = new Node(x);
    Node* prev = head;
    while (true) {
        cin >> x;
        if (x == -1) 
            break;
        Node* temp = new Node(x);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}
// PRINT
Node* printDLL(Node* head){
    Node* temp = head; 
    while(temp!= NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
    return head;
}
//REVERSE O(2n),O(n)
Node* reverseDLL(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* temp = head;
    stack<int> s;
    while(temp!=nullptr){
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        temp->data = s.top();
        s.pop();
        temp = temp->next;
    }
    return head;
}
//Optimal O(n),O(1)
Node* optimalReverseDLL(Node* head){
    if(head == nullptr || head->next == nullptr)
        return head;
    Node* last = nullptr;
    Node* cur = head;
    while(cur!=nullptr){
        last = cur->back;
        cur->back = cur->next;
        cur->next = last;
        cur = cur->back;
    }
    return last->back;
}
int main(){
    Node* head = nullptr;
    int choice;

    cout << "Create Double linked list (-1 to stop):\n";
    head = createDLL();

    printDLL(head);

    Node* revhead  = reverseDLL(head);
    printDLL(revhead);

    Node* opthead = optimalReverseDLL(head);
    printDLL(opthead);
    return 0;
}