#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    // Constructor to initialize node
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(ListNode*& head, int newData) {
    ListNode* newNode = new ListNode(newData);
    if (head == NULL) {
        head = newNode;  // If the list is empty, make the new node the head
        return;
    }
    
    ListNode* temp = head;
    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Insert the new node at the end
    temp->next = newNode;
}

// Function to display the linked list
void displayList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    // Function to modify the list by removing nodes with values present in 'nums'
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        // Creating a dummy node to handle cases where head itself might be removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* pre = dummy;
        while (pre->next != NULL) {
            if (s.count(pre->next->val)) {
                // Remove the node if its value is in the set
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }

        return dummy->next;  // Return the modified list starting from the original head
    }
};

int main() {
    ListNode* head = NULL;
    int n, value;

    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    // Inserting values at the tail of the list
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    // Reading the elements to remove
    vector<int> nums(n);
    cout << "Enter the elements to remove from the list: ";
    for (int i = 1; i < n; i++) {
        cin >> nums[i];
    }

    // Creating an instance of Solution and modifying the list
    Solution solution;
    ListNode* result = solution.modifiedList(nums, head);

    // Display the modified list
    cout << "Modified List: ";
    displayList(result);

    return 0;
}
