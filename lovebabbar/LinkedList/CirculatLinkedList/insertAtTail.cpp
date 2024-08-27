#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    `Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
};

void insertAtTail(Node*& head, int newData) {
    Node* newNode = new Node(newData);

    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void displayList(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data;
        if (temp->next != head) {
            cout << "<->";
        }
        temp = temp->next;
    } while (temp != head);
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
    displayList(head);
    return 0;
}