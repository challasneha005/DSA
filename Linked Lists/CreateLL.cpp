// CREATE LINKED LIST 
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
Node* createLL(){
    int x;
    cin >> x;

    Node* head = nullptr;
    Node* tail = nullptr;

    while(x!= -1){
        Node* temp = new Node(x);
        if(head == nullptr){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        cin >> x;
    }
    return head;
}
void printLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main(){
     
    cout << "Enter elements of linked list (end with -1): ";
    Node* head = createLL();

    cout << "Linked List: ";
    printLL(head);
    return 0;
}