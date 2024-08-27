#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
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

void deleteAtPosition(Node*& head, int position) {
    if (head == NULL || position <= 0) {
        cout << "Invalid position or the list is empty." << endl;
        return;
    }
    if (position == 1) {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        cout << "Position out of bounds." << endl;
        return;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << "<->";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    int n, value;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    int position;
    cout << "Enter the position to delete: ";
    cin >> position;

    deleteAtPosition(head, position);

    cout << "List after deletion: ";
    displayList(head);

    return 0;
}
