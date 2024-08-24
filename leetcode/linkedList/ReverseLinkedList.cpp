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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;  
            curr->next = prev; 
            prev = curr;    
            curr = next;  
        }
        
        return prev;  
    }

    void displayList(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->val <<" -> ";
            temp = temp->next;
        }
        cout <<"NULL";
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

int main() {
    ListNode* head = NULL;
    int n, value;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    Solution solution;
    head = solution.reverseList(head);
    
    cout << "Reversed List: ";
    solution.displayList(head);

    return 0;
}