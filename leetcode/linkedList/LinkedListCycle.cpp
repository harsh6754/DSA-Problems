#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to check if the linked list has a cycle
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> nodeSet;
    while (head != NULL) {
        if (nodeSet.find(head) != nodeSet.end()) {
            return true;
        }
        nodeSet.insert(head);
        head = head->next;
    }
    return false;
}

// Function to create a linked list from user input
ListNode* createLinkedList(int n) {
    ListNode *head = NULL, *tail = NULL;
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ListNode* newNode = new ListNode(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to create a cycle in the linked list at a given position
void createCycle(ListNode *head, int pos, int n) {
    if (pos < 0) return;  // No cycle
    ListNode *cycleNode = NULL, *tail = head;
    int index = 0;
    while (tail->next != NULL) {
        if (index == pos) {
            cycleNode = tail;
        }
        tail = tail->next;
        index++;
    }
    if (cycleNode != NULL) {
        tail->next = cycleNode;
    }
}

int main() {
    int n, pos;
    
    cout << "Enter the number of nodes in the linked list: ";
    cin >> n;
    
    if (n == 0) {
        cout << "The linked list is empty, no cycle." << endl;
        return 0;
    }

    ListNode* head = createLinkedList(n);

    cout << "Enter the position of the node where the cycle starts (-1 for no cycle): ";
    cin >> pos;

    createCycle(head, pos, n);

    if (hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}
