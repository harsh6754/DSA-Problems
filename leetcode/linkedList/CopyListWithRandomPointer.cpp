#include <unordered_map>
#include <iostream>
using namespace std;

// List template
class Node {
public:
    int val;
    Node* next;
    Node* random;

    // Init constructor
    Node(int val, Node* next = nullptr, Node* random = nullptr)
    :
    val(val), next(next), random(random) {}

    // Method to insert a node in the list - O(1) & O(1)
    void insertNode(Node*& headNode, Node*& lastNode, int key) {
        Node* newNode = new Node(key);

        if (!headNode)
            headNode = newNode, lastNode = newNode;
        else    
            lastNode->next = newNode, lastNode = lastNode->next;

        lastNode->next = nullptr;
    }

    // Method to print the list - O(N) & O(1)
    void printList(Node* headNode) {
        while (headNode) {
            cout << "[" << headNode->val << ", ";

            if (headNode->random) 
                cout << headNode->random->val;
            else 
                cout << "null";

            cout << "]";

            if (headNode->next)
                cout << ", ";

            headNode = headNode->next;
        }
        cout << endl;
    }
    
    // Method to delete the list - O(N) & O(1)
    void deleteList(Node*& headNode) {
        while (headNode) {
            Node* nextNode = headNode->next;
            delete headNode;
            headNode = nextNode;
        }
    }
};

// Solution class for copying the list with random pointers
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* temp = head;
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head];
    }
};

// Driver code
int main() {
    int testCases;
    cout << "Enter the total number of testcases: ";
    cin >> testCases;

    while (testCases--) {
        // Input the length of the list
        int n;
        cout << "\nEnter the size of the list: ";
        cin >> n;

        // Check the given size is lying within the problem constraints or not
        if (n < 0 || n > 1000) {
            cout << "Enter a size which lies between 0 and 1000!\n";
        } else {
            Node* headNode = nullptr, *lastNode = nullptr;

            // Tracks the nodes based on their positions
            unordered_map<int, Node*> mp;

            // Input and create the nodes of the list
            for (int pos = 1; pos <= n;) {
                int key;
                cout << "Enter the value of " << pos << "th node: ";
                cin >> key;

                // Check the given value is lying within the problem constraints or not
                if (key < -1e4 || key > 1e4) {
                    cout << "Enter a value which lies between -10^4 and 10^4!\n";
                } else {
                    headNode->insertNode(headNode, lastNode, key);
                    mp[pos] = lastNode;
                    ++pos;
                }
            }

            // Link the random pointers of each node
            cout << "\nLink the random pointers: \n";
            for (int pos = 1; pos <= n; ++pos) {
                int linkPos;
                cout << "Enter the position for the " << pos << " node to link with: ";
                cin >> linkPos;

                if (linkPos < 1 || linkPos > n) {
                    cout << "No node lies at the entered position hence the random pointer is set to null for the node!\n";
                } else {
                    mp[pos]->random = mp[linkPos];
                }
            }

            // Print original list
            cout << "\nOriginal list traversal:\n";
            headNode->printList(headNode);

            // Create the copied list using the Solution class
            Solution solution;
            Node* copiedList = solution.copyRandomList(headNode);

            // Print copied list
            cout << "\nCopied list traversal:\n";
            headNode->printList(copiedList);

            // Deletion call for both lists
            headNode->deleteList(headNode);
            copiedList->deleteList(copiedList);
        }
    }

    return 0;
}
