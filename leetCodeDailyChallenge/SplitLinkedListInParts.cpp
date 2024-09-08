#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to insert a node at the tail of the linked list
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

// Solution class that splits the linked list into k parts
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        int length = 0;
        ListNode* curr = head;
        
        // Calculate the length of the list
        while (curr) {
            length++;
            curr = curr->next;
        }

        int partSize = length / k;
        int extraNodes = length % k;

        curr = head;
        for (int i = 0; i < k && curr; i++) {
            result[i] = curr;
            int currPartSize = partSize + (extraNodes-- > 0 ? 1 : 0);
            for (int j = 1; j < currPartSize; j++) {
                curr = curr->next;
            }
            ListNode* nextPart = curr->next;
            curr->next = nullptr;
            curr = nextPart;
        }
        return result;
    }
};

// Function to display the list parts
void displayList(const vector<ListNode*>& parts) {
    for (int i = 0; i < parts.size(); i++) {
        cout << "Part " << i + 1 << ": ";
        ListNode* temp = parts[i];
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    ListNode* head = NULL;
    int n, value;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value " << i + 1 << ": ";
        cin >> value;
        insertAtTail(head, value);
    }

    int k;
    cout << "Enter the number of parts: ";
    cin >> k;

    Solution solution;
    vector<ListNode*> result = solution.splitListToParts(head, k);
    displayList(result);

    return 0;
}
