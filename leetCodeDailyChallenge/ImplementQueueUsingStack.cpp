#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
    }
    void push(int x) {

        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }

    int peek() {
        return st1.top();
    }

    bool empty() {
        return st1.empty();
    }
};

int main() {
    MyQueue queue;
    char choice;
    do {
        int val;
        cout << "Enter value to push: ";
        cin >> val;
        queue.push(val);

        cout << "Do you want to push more elements? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    while (!queue.empty()) {
        cout << "Front element: " << queue.peek() << endl;
        cout << "Popped: " << queue.pop() << endl;
    }

    return 0;
}
