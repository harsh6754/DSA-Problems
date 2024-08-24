#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    // Corrected Constructor
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void InsertAtTail(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1, * q = l2, * curr = dummyHead;
        int carry = 0;
        while (p != NULL || q != NULL) {
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (p != NULL) p = p->next;
            if (q != NULL) q = q->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};

int main() {
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    int n, value;

    // Input for the first list
    cout << "Enter the number of nodes in List1: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter List1 value " << i + 1 << ": ";
        cin >> value;
        InsertAtTail(head1, value);
    }

    // Input for the second list
    cout << "Enter the number of nodes in List2: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter List2 value " << i + 1 << ": ";
        cin >> value;
        InsertAtTail(head2, value);
    }

    Solution solution;
    ListNode* head = solution.addTwoNumbers(head1, head2);

    // Displaying the result list
    cout << "Resultant List: ";
    displayList(head);

    return 0;
}
