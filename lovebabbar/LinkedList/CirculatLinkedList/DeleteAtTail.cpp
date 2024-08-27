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

void deleteAtTail(Node*& head) {
    if (head == NULL) return;

    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* lastNode = temp->next;
        temp->next = head;
        delete lastNode;
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

    deleteAtTail(head);
    displayList(head);

    return 0;
}
