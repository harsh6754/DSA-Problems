#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int val) : data(val), next(NULL) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() : head(NULL) {}

    void insert(int data) {
        ListNode* newNode = new ListNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            ListNode* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    ListNode* getHead() {
        return head;
    }

    void printList() {
        ListNode* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int position = 0;
        
        while (curr != nullptr && curr->next != nullptr) {
            if (prev != nullptr) {
                if ((curr->data > prev->data && curr->data > curr->next->data) || 
                    (curr->data < prev->data && curr->data < curr->next->data)) {
                    criticalPoints.push_back(position);
                }
            }
            prev = curr;
            curr = curr->next;
            position++;
        }
        
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();
        
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        return {minDistance, maxDistance};
    }
};

int main() {
    LinkedList list;
    Solution solution;
    int n, value;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        list.insert(value);
    }

    cout << "The linked list is: ";
    list.printList();

    vector<int> result = solution.nodesBetweenCriticalPoints(list.getHead());
    cout << "Minimum distance between critical points: " << result[0] << endl;
    cout << "Maximum distance between critical points: " << result[1] << endl;

    return 0;
}
