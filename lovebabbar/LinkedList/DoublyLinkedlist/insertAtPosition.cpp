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
        this->prev = NULL;
    }
};

// Function to insert at the end of the doubly linked list
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

// Function to insert a node at a specific position
void insertAtPosition(Node*& head, int newData, int position) {
    Node* newNode = new Node(newData);

    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Function to display the doubly linked list
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
    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter the value " << i+1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    int value2;
    cout << "Enter the value to insert: ";
    cin >> value2;

    int position;
    cout << "Enter the position to insert the value: ";
    cin >> position;

    insertAtPosition(head, value2, position);

    displayList(head);
    return 0;
}
