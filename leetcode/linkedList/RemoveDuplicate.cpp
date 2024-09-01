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

void insertAtTail(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head && head->val == val) {
            head = head->next;
        }

        ListNode* curr = head;
        while (curr && curr->next) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};

int main() {
    ListNode* head = NULL;
    int n, value;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    int target;
    cin >> target;

    Solution solution;
    ListNode* result = solution.removeElements(head, target);
    displayList(result);

    return 0;
}
