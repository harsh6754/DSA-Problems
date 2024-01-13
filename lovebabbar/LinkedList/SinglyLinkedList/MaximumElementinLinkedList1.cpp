#include <iostream>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find the maximum element in the linked list
int findMaxElement(Node* head) {
    // Check if the linked list is empty
    if (head == nullptr) {
        cout << "Linked List is empty." << endl;
        return -1; // Assuming -1 as an indicator for an empty list
    }

    int maxElement = head->data;
    Node* current = head->next;

    // Traverse the linked list to find the maximum element
    while (current != nullptr) {
        if (current->data > maxElement) {
            maxElement = current->data;
        }
        current = current->next;
    }

    return maxElement;
}

int main() {

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 5; ++i) {
        int val;
        cin >> val;

        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int maxElement = findMaxElement(head);
    
    if (maxElement != -1) {
        cout << "Maximum Element: " << maxElement << endl;
    }

    // Freeing memory: Release allocated memory for the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
