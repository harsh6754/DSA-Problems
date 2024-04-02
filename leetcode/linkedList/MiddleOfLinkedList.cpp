#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Function to find the middle node of a linked list
Node *findMiddle(Node *head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to insert a node at the end of the linked list
void insertNode(Node *&head, int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printLinkedList(Node *head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    Node *head = nullptr;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        insertNode(head, val);
    }

    cout << "Linked List: ";
    printLinkedList(head);

    Node *middle = findMiddle(head);
    if (middle != nullptr) {
        cout << "Middle element of the linked list: " << middle->data << endl;
    } else {
        cout << "Linked list is empty." << endl;
    }

    return 0;
}
