#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev= NULL;
    }
};
void insertAtTail(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtHead(Node*& head) {
    if (head == NULL) {
        cout << "The list is already empty." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
}

void displayList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        if(temp->next != NULL){
            cout << "<->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    int n,value;
    cin>>n;
    for(int i = 0;i<n;i++){
        cout<<"Enter the value "<<i+1<<":";
        cin>>value;
        insertAtTail(head,value);
    }
    deleteAtHead(head);
    displayList(head);
    return 0;
}