#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Solution{
public:
    Node *ReverseLinkedList(Node *tail) {
        if (tail == NULL || tail->next == NULL) {
            return tail;
        }
        
        Node *rest = ReverseLinkedList(tail->next);

         tail->next->next = tail;

        tail->next = NULL;

        return rest;
    }
};

void InsertAtTail(Node *&tail, int data) {
    Node *temp = new Node(data);
    if (tail == NULL) {
        tail = temp;
        return;
    }
    Node *current = tail;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

void print(Node *tail) {
    Node *temp = tail;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node *tail = NULL;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        InsertAtTail(tail, data);
    }

    cout << "Original List: ";
    print(tail);

    Solution solution;
    tail = solution.ReverseLinkedList(tail);

    cout << "After Recursion: ";
    print(tail);

    return 0;
}
