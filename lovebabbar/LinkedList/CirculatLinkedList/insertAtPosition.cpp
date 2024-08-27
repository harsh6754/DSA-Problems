#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
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

void insertAtPosition(Node*& head, int position, int newData) {
    if (position == 1) {
        Node* newNode = new Node(newData);
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    } else {
        Node* temp = head;
        for (int i = 1; i < position - 1 && temp->next != head; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(newData);
        newNode->next = temp->next;
        temp->next = newNode;
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

int main() {
    Node* head = NULL;
    int n, value;
    
    // Input number of nodes
    cin >> n;

    // Insert elements at the tail
    for (int i = 0; i < n; i++) {
        cout << "Enter the value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    // Input value and position for insertion
    int val, position;
    cout << "Enter the value to insert: ";
    cin >> val;
    cout << "Enter the position to insert: ";
    cin >> position;

    // Insert at the specified position
    insertAtPosition(head, position, val);

    // Display the list
    displayList(head);

    return 0;
}
