#include<bits/stdc++.h>
using namespace std;

class ListNode {
    public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(ListNode*& head, int newData) {
    ListNode* newNode = new ListNode(newData);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;
}

class Solution {
    public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);  // Dummy node for list of elements less than x
        ListNode* greaterHead = new ListNode(0);  // Dummy node for list of elements greater or equal to x

        ListNode* less = lessHead;
        ListNode* greater = greaterHead;

        while (head != nullptr) {
            if (head->data < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr; // Important to avoid cycle
        less->next = greaterHead->next;

        ListNode* partitionedHead = lessHead->next;
        delete lessHead;
        delete greaterHead;
        
        return partitionedHead;
    }
};

int main() {
    ListNode* head = NULL;

    int n, value;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the Value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    int x;
    cout << "Enter the partition value: ";
    cin >> x;

    Solution solution;
    head = solution.partition(head, x);
    displayList(head);

    return 0;
}
