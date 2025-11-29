// ADD 2 NUMBERS IN LINKED LIST O(max(n1,n2)) , O(max(n1,n2))
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
// PRINT
void printLL(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
//ADD
Node* addTwoNum(Node* h1,Node*h2){
    Node* dummyHead = new Node(-1);
    Node* cur = dummyHead;
    Node* t1 = h1;
    Node* t2 = h2;
    int carry = 0;
    while(t1!=nullptr || t2!=nullptr){
        int sum = carry;
        if(t1)
            sum+= t1->data;
        if(t2)
            sum+=t2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;

        cur->next = newNode;
        cur = cur->next;

        if(t1)
            t1 = t1->next;
        if(t2)
            t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        cur->next = newNode;
    }
    return dummyHead->next;
}
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    cout << "Create LL1 (-1 to stop):\n";
    head1 = createLL();

    cout << "Create LL2 (-1 to stop):\n";
    head2 = createLL();

    printLL(head1);
    printLL(head2);

    Node* head = addTwoNum(head1,head2);
    cout << "After Sum : "<< endl;
    printLL(head);

    return 0;
}