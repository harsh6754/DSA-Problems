#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to merge nodes in between zeros
ListNode* mergeNodes(ListNode* head) {
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    ListNode* temp = head->next;
    int currentSum = 0;
    
    while (temp) {
        if (temp->val != 0) {
            currentSum += temp->val;
        } else {
            if (currentSum > 0) {
                current->next = new ListNode(currentSum);
                current = current->next;
                currentSum = 0;
            }
        }
        temp = temp->next;
    }
    
    return dummy.next;
}

// Helper function to create a linked list from user input
ListNode* createLinkedList() {
    int val;
    ListNode dummy(0);
    ListNode* current = &dummy;
    
    cout << "Enter values for the linked list (end with -1): " << endl;
    while (true) {
        cin >> val;
        if (val == -1) break;
        current->next = new ListNode(val);
        current = current->next;
    }
    
    return dummy.next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create linked list from user input
    ListNode* head = createLinkedList();
    
    // Merge nodes in between zeros
    ListNode* mergedHead = mergeNodes(head);
    
    // Print the resulting linked list
    cout << "Merged linked list: ";
    printLinkedList(mergedHead);
    
    return 0;
}
