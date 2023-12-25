#include <iostream>
#include <stack>
using namespace std;

class Stack {
public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int element) {
        if (isFull()) {
            throw overflow_error("Stack Overflow");
        }
        top++;
        arr[top] = element;
    }

    void pop() {
        if (isEmpty()) {
            throw underflow_error("Stack Underflow");
        }
        top--;
    }

    int peek() const {
        if (isEmpty()) {
            throw runtime_error("Stack is Empty");
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == size - 1;
    }
};

int main() {
    Stack st(10);

    try {
        st.push(22);
        st.push(43);
        st.push(44);
        st.push(22);
        st.push(43);
        st.push(44);
        st.push(50);
        st.push(100);
        st.push(110);
        st.push(10);
        //st.push(20);

        cout << st.peek() << endl;

        st.pop();

        cout << st.peek() << endl;

        st.pop();

        cout << st.peek() << endl;

        st.pop();

        cout << st.peek() << endl;

        st.pop();

        cout << st.peek() << endl;

        st.pop();

        cout << st.peek() << endl;

        if (st.isEmpty()) {
            cout << "Stack is Empty" << endl;
        } else {
            cout << "Stack is not Empty" << endl;
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
