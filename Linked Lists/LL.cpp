// COMPLETE INSERTION AND DELETION
// SEARCH,LENGTH
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
// LENGTH
int countLL(Node* head) {
    int count =0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    } 
    return count;
}
// SEARCH   
bool check(Node* head,int val){
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}
// DELETION at head
Node* deleteHead(Node * head){
    if(head == nullptr) 
        return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
// DELETION at tail
Node* deleteTail(Node* head){
    if(head == nullptr)
        return nullptr;
    if( head-> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next->next !=nullptr){
        temp = temp->next;
    }
    delete(temp->next);
    temp->next = nullptr;
    return head;
}
// DELETION at kth element
Node* deletekthEl(Node* head,int k){
    if(head == nullptr)
        return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        count++;
        if(count  ==k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp =temp->next;
    }
    return head;
} 
// DELETION at value  
Node* deleteByValue(Node* head,int val){
    if(head == nullptr)
        return head;
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    } 
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){ 
        if(temp->data == val){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp =temp->next;
    }
    return head;
} 


// INSERTION at head
Node* inserthead(Node* head,int val){
    if(head == nullptr)
        return new Node(val);
    Node * temp = new Node(val);
    temp->next = head;
    return temp;
}
// INSERTION at tail
Node* inserttail(Node* head,int val){
    if(head == nullptr)
        return new Node(val);
    Node *temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}
// INSERTION at kth element
Node* insertkthEl(Node* head,int k,int val){
    if(head == nullptr){
        if(k==1)
            return new Node(val);
        else    
            return nullptr;
    }
    if(k==1){
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    int count = 0;
    Node* temp = head;
    while(temp!=nullptr){
        count++;
        if(count == k-1){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp =  temp->next;
    }
    return head;
}
// INSERTION at val before element- it is present
Node* insertkElbefore(Node* head,int k,int val){
    if(head == nullptr)
        return nullptr; 
    if(head->data==k){
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    int count = 0;
    bool flag = false;
    Node* temp = head;
    while(temp!=nullptr){
        count++;
        if(temp->next->data == k){
            Node* x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            flag = true;
            break;
        }
        temp =  temp->next;
    } 
    return head;
}
int main() {
    Node* head = nullptr;
    int choice;

    cout << "Create linked list (-1 to stop):\n";
    head = createLL();

    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Print Linked List\n";
        cout << "2. Length of Linked List\n";
        cout << "3. Search an element\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Delete k-th Element\n";
        cout << "7. Delete by Value\n";
        cout << "8. Insert at Head\n";
        cout << "9. Insert at Tail\n";
        cout << "10. Insert at k-th Position\n";
        cout << "11. Insert Before Value\n";
        cout << "12. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 12) break;

        int k, val;

        switch (choice) {

        case 1:
            printLL(head);
            break;

        case 2:
            cout << "Length = " << countLL(head) << "\n";
            break;

        case 3:
            printLL(head);
            cout << "Enter value to search: ";
            cin >> val;
            if (check(head, val)) cout << "Found\n";
            else cout << "Not Found\n";
            break;

        case 4:
            cout << "Before :"; printLL(head);
            head = deleteHead(head);
            cout << "After:"; printLL(head);
            cout << "Head deleted";

            break;

        case 5:
            cout << "Before :"; printLL(head);
            head = deleteTail(head);
            cout << "After:"; printLL(head);
            cout << "Tail Deleted";
            break;

        case 6:
            cout << "Enter k: ";
            cin >> k;
            cout << "Before :"; printLL(head);
            head = deletekthEl(head, k);
            cout << "After:"; printLL(head);
            cout << "Kth  position element deleted";
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            cout << "Before :"; printLL(head);
            head = deleteByValue(head, val);  
            cout << "After:"; printLL(head);  
            cout << val << " is deleted"; 
            break;

        case 8:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Before :"; printLL(head);
            head = inserthead(head, val);
            cout << "After:"; printLL(head);  
            cout << val << " Inserted at head";
            break;

        case 9:
            cout << "Enter value: ";
            cin >> val;
            cout << "Before :"; printLL(head);
            head = inserttail(head, val);
            cout << "After:"; printLL(head);  
            cout << val << " Inserted at Tail";
            break;

        case 10:
            cout << "Enter k and value: ";
            cin >> k >> val;
            cout << "Before :"; printLL(head);
            head = insertkthEl(head, k, val);
            cout << "After:"; printLL(head);  
            cout << val << " Inserted at kth position";
            break;

        case 11:
            cout << "Enter value to insert before and new value: ";
            cin >> k >> val;
            cout << "Before :"; printLL(head);
            head = insertkElbefore(head, k, val);
            cout << "After:"; printLL(head);  
            cout << val << " Inserted before "<<k;
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}