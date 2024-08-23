#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to insert a new node after a node with the target value
void insertAtMiddle(Node*& head, int newData, int target) {
    Node* newNode = new Node(newData);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    // Traverse the list to find the node with the target value
    while (temp != nullptr && temp->data != target) {
        temp = temp->next;
    }

    // If the target node is found
    if (temp != nullptr) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        // If target is not found, we can choose to insert at the end
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = newNode;
    }
}

// Function to display the linked list
void displayList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, target;

    cout << "Enter the initial number of elements: ";
    cin >> n;

    // Create the initial list
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertAtMiddle(head, value, -1); // -1 as target to insert at end
    }

    cout << "Enter the value to insert: ";
    cin >> value;
    cout << "Enter the target value after which to insert: ";
    cin >> target;

    insertAtMiddle(head, value, target);

    displayList(head);

    return 0;
}

