#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* link;
    Node(int n) {
        this->data = n;
        this->link = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int data) {
        Node* temp = new Node(data);
        if (!temp) {
            cout << "\nStack Overflow";
            exit(1);
        }
        temp->data = data;
        temp->link = top;
        top = temp;
    }

    bool isEmpty() {
        return top == NULL;
    }


    void display() {
        Node* temp;
        if (top == NULL) {
            cout << "\nStack Underflow";
            exit(1);
        } else {
            temp = top;
            while (temp != NULL) {
                cout << temp->data;
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};

int main() {
    Stack s;

    int n, value;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        s.push(value);
    }

    



    s.display();

    return 0;
}
