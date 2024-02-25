#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
public:
    stack<int> s;

    void push(int data) {
        if (s.empty()) {
            s.push(data);
            s.push(data);
        } else {
            if (data < s.top()) {
                s.push(data);
                s.push(data);
            } else {
                int mini = s.top();
                s.push(data);
                s.push(mini);
            }
        }
    }

    void pop() {
        if (s.empty())
            return;

        s.pop();
        s.pop();
    }

    int top() {
        if (s.empty())
            return -1;

        int temp1 = s.top();
        s.pop();
        int temp2 = s.top();
        s.push(temp1);

        return temp2;
    }

    int getMin() {
        if (s.empty())
            return -1;

        return s.top();
    }
};

int main() {
    SpecialStack myStack;

    // Example usage:
    // Push elements into the special stack
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        myStack.push(element);
    }

    // Perform operations on the special stack
    cout << "Top element: " << myStack.top() << endl;
    cout << "Minimum element: " << myStack.getMin() << endl;

    myStack.pop();

    cout << "After popping, new top element: " << myStack.top() << endl;
    cout << "Minimum element: " << myStack.getMin() << endl;

    return 0;
}
