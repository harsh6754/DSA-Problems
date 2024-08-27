#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
    ~Node() { 
        if (next) delete next;
    }
};

class Solution {
public:
    int findMinSum(Node* L1, Node* L2) {
        if (!L1 || !L2) return 0;  // Condition 1: Both lists must be non-empty.
        if (getLength(L1) != getLength(L2)) return 0;  // Condition 2: Lengths must be the same.

        removeDuplicates(L1);
        removeDuplicates(L2);

        if (hasDuplicates(L1) || hasDuplicates(L2)) return 0;  // Condition 3: No duplicates allowed.

        int sum1 = calculateSum(L1);
        int sum2 = calculateSum(L2);

        return min(sum1, sum2);
    }

private:
    int getLength(Node* head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

    void removeDuplicates(Node*& head) {
        unordered_set<int> seen;
        Node* curr = head;
        while (curr) {
            if (seen.find(curr->data) != seen.end()) {
                Node* toDelete = curr;
                if (curr->prev) curr->prev->next = curr->next;
                if (curr->next) curr->next->prev = curr->prev;
                if (curr == head) head = curr->next;
                curr = curr->next;
                toDelete->next = nullptr;
                delete toDelete;
            } else {
                seen.insert(curr->data);
                curr = curr->next;
            }
        }
    }

    int calculateSum(Node* head) {
        int sum = 0;
        while (head) {
            sum += head->data;
            head = head->next;
        }
        return sum;
    }

    bool hasDuplicates(Node* head) {
        unordered_set<int> seen;
        while (head) {
            if (seen.find(head->data) != seen.end()) {
                return true;
            }
            seen.insert(head->data);
            head = head->next;
        }
        return false;
    }
};

Node* createList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    Solution sol;

    int n1, n2;
    cout << "Enter the number of elements in list L1: ";
    cin >> n1;
    Node* L1 = createList(n1);

    cout << "Enter the number of elements in list L2: ";
    cin >> n2;
    Node* L2 = createList(n2);

    int minSum = sol.findMinSum(L1, L2);
    cout << "Result: " << minSum << endl;

    delete L1;
    delete L2;

    return 0;
}
