#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Solution {
public:
    Node* reverseList(Node *head) {
        Node *prev = nullptr;
        Node *current = head;
        Node *nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};

void InsertAtTail(Node *&head, int data) {
    Node *temp = new Node(data);
    if (head == nullptr) {
        head = temp;
        return;
    }
    Node *current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = temp;
}

void print(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *head = nullptr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int data;
        cin >> data;
        InsertAtTail(head, data);
    }

    cout << "Original list: ";
    print(head);

    Solution solution;
    head = solution.reverseList(head);

    cout << "Reversed list: ";
    print(head);

    return 0;
}
