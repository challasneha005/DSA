// COMPLETE INSERTION AND DELETION
// SEARCH,LENGTH
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
// LENGTH
int countDLL(Node* head){
    int count =0;
    Node* temp = head; 
    while(temp!= NULL){
        temp = temp->next;
        count++;
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
    if(head == nullptr || head->next == nullptr) 
        return nullptr;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
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
    while(temp->next !=nullptr){
        temp = temp->next;
    }
    Node* prev = temp->back;
    prev->next = nullptr;
    delete(temp);
    return head;
}
// DELETION at kth element
Node* deletekthEl(Node* head,int k){
    if(head == nullptr)
        return nullptr;
    int count =0;
    Node* temp = head;
    while(temp!=nullptr){
        count++;
        if(count  ==k)
            break;
        temp = temp->next;
    }
    Node* prev= temp->back;
    Node* front = temp->next;
    if(prev == nullptr && front == nullptr){
        delete temp;
        return nullptr;
    }
    else if(prev == nullptr)
        return deleteHead(head);
    else if(front == nullptr)
        return deleteTail(head);
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}   
// DELETION at value IT CANT BE HEAD  
Node* deleteByValue(Node* head,int val){
    if(head == nullptr)
        return head;
    if(head->data == val){
        Node* temp = head;
        head = head->next;
        if(head!=nullptr)
            head->back = nullptr;
        delete temp;
        return head;
    } 
    Node* temp = head;
    while(temp!=nullptr){ 
        if(temp->data == val){
            Node* prev = temp->back;
            Node* front = temp->next;
            if(front ==nullptr){
                prev->next = nullptr;
                temp->back = nullptr;
                delete temp;
                break;
            }
            else{
                prev->next = front;
                front->back = prev;
                temp->next = nullptr;
                temp->back = nullptr;
                delete temp;
                break;
            }
        }
        temp = temp->next;
    }
    return head;
} 
// INSERTION BEFORE HEAD
Node* inserthead(Node* head,int val){
    if(head == nullptr)
        return new Node(val);
    Node * temp = new Node(val);
    temp->next = head;
    head->back = temp;
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
    newNode->back = temp;
    return head;
}
// INSERTION BEFORE TAIL
Node* insertBeforeTail(Node* head,int val){
    if(head == nullptr ||head->next == nullptr){
        Node * tempnew = new Node(val);
        tempnew->next = head;
        if (head != nullptr)
            head->back = tempnew;
    return tempnew;
    }
        
    Node* temp = head;
    while(temp->next->next!= nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next->back = newNode;
    newNode->back = temp;
    temp->next = newNode ;

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
        Node* tempnew = new Node(val);
        tempnew->next = head;
        head->back = tempnew;
        return tempnew;
    }
    int count = 0;
    Node* temp = head;
    Node* prev =nullptr;
    while(temp!=nullptr){
        count++;
        if(count == k-1){
            Node* x = new Node(val);
            x->next = temp->next;
            x->back = temp;
            if(temp->next != nullptr) // if not inserting at tail
                temp->next->back = x;
            temp->next = x;
            break;
        }
        prev = temp;
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
        head->back = temp;
        return temp;
    }
    bool flag = false;
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == k){
            Node* prev = temp->back;
            Node* x = new Node(val);
            x->next = temp;
            temp->back = x;
            prev->next = x;
            x->back = prev;
            flag = true;
            break;
        }
        temp =  temp->next;
    } 
    return head;
}
int main(){
    Node* head = nullptr;
    int choice;

    cout << "Create Double linked list (-1 to stop):\n";
    head = createDLL();
    
    while (true) {
        cout << "\n------ MENU ------\n";
        cout << "1. Print Double Linked List\n";
        cout << "2. Length of Double Linked List\n";
        cout << "3. Search an element\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Delete k-th Element\n";
        cout << "7. Delete by Value\n";
        cout << "8. Insert at Head\n";
        cout << "9. Insert at Tail\n";
        cout << "10. Insert at Before Tail\n";
        cout << "11. Insert at k-th Position\n";
        cout << "12. Insert Before Value\n";
        cout << "13. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 13) break;

        int k, val;

        switch (choice) {

        case 1:
            printDLL(head);
            break;

        case 2:
            cout << "Length = " << countDLL(head) << "\n";
            break;

        case 3:
            printDLL(head);
            cout << "Enter value to search: ";
            cin >> val;
            if (check(head, val)) cout << "Found\n";
            else cout << "Not Found\n";
            break;

        case 4:
            cout << "Before :"; printDLL(head);
            head = deleteHead(head);
            cout << "After:"; printDLL(head);
            cout << "Head deleted";

            break;

        case 5:
            cout << "Before :"; printDLL(head);
            head = deleteTail(head);
            cout << "After:"; printDLL(head);
            cout << "Tail Deleted";
            break;

        case 6:
            cout << "Enter k: ";
            cin >> k;
            cout << "Before :"; printDLL(head);
            head = deletekthEl(head, k);
            cout << "After:"; printDLL(head);
            cout << "Kth  position element deleted";
            break;

        case 7:
            cout << "Enter value to delete: ";
            cin >> val;
            cout << "Before :"; printDLL(head);
            head = deleteByValue(head, val);  
            cout << "After:"; printDLL(head);  
            cout << val << " is deleted"; 
            break;

        case 8:
            cout << "Enter value to insert: ";
            cin >> val;
            cout << "Before :"; printDLL(head);
            head = inserthead(head, val);
            cout << "After:"; printDLL(head);  
            cout << val << " Inserted at head";
            break;

        case 9:
            cout << "Enter value: ";
            cin >> val;
            cout << "Before :"; printDLL(head);
            head = inserttail(head, val);
            cout << "After:"; printDLL(head);  
            cout << val << " Inserted at Tail";
            break;

        case 10:
            cout << "Enter value: ";
            cin >> val;
            cout << "Before :"; printDLL(head);
            head = insertBeforeTail(head, val);
            cout << "After:"; printDLL(head);  
            cout << val << " Inserted at Before Tail";
            break;

        case 11:
            cout << "Enter k and value: ";
            cin >> k >> val;
            cout << "Before :"; printDLL(head);
            head = insertkthEl(head, k, val);
            cout << "After:"; printDLL(head);  
            cout << val << " Inserted at kth position";
            break;

        case 12:
            cout << "Enter value to insert before and new value: ";
            cin >> k >> val;
            cout << "Before :"; printDLL(head);
            head = insertkElbefore(head, k, val);
            cout << "After:"; printDLL(head);  
            cout << val << " Inserted before "<<k;
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
