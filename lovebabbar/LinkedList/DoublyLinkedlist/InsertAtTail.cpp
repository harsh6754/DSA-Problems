#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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


void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";  // Separator between nodes
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
        cout<<"enter the value"<<i+1<<":";
        cin>>value;
        insertAtTail(head,value);
    }

    displayList(head);

    return 0;
}