#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(ListNode*& head, int newData) {
    ListNode* newNode = new ListNode(newData);
    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* removeFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        
      
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }
        
     
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        
        
        second->next = second->next->next;
        
        return dummy->next;
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

    int targetNode;
    cout << "Enter the position from end to remove: ";
    cin >> targetNode;

    Solution solution;
    ListNode* result = solution.removeFromEnd(head, targetNode);

    cout << "Updated List: ";
    displayList(result);

    return 0;
}
