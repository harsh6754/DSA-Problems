#include <iostream>
using namespace std;

class twoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    // Constructor
    twoStacks(int n)
    {
        size = n;
        arr = new int[n];
        top1 = n / 2 + 1;
        top2 = n / 2;
    }

    // Method to push an element x to stack1
    void push1(int x)
    {
        // There is at least one empty
        // space for new element
        if (top1 > 0) {
            top1--;
            arr[top1] = x;
        }
        else {
            cout << "Stack Overflow"
                << " By element : " << x << endl;
            return;
        }
    }

    // Method to push an element
    // x to stack2
    void push2(int x)
    {

        // There is at least one empty
        // space for new element
        if (top2 < size - 1) {
            top2++;
            arr[top2] = x;
        }
        else {
            cout << "Stack Overflow"
                << " By element : " << x << endl;
            return;
        }
    }

    // Method to pop an element from first stack
    int pop1()
    {
        if (top1 <= size / 2) {
            int x = arr[top1];
            top1++;
            return x;
        }
        else {
            cout << "Stack UnderFlow";
            exit(1);
        }
    }

    // Method to pop an element
    // from second stack
    int pop2()
    {
        if (top2 >= size / 2 + 1) {
            int x = arr[top2];
            top2--;
            return x;
        }
        else {
            cout << "Stack UnderFlow" << endl;
            exit(1);
        }
    }
};

/* Driver program to test twoStacks class */
int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    twoStacks ts(size);
    
    int element;
    cout << "Enter elements for stack 1: ";
    for (int i = 0; i < size/2; ++i) {
        cin >> element;
        ts.push1(element);
    }

    cout << "Enter elements for stack 2: ";
    for (int i = 0; i < size/2; ++i) {
        cin >> element;
        ts.push2(element);
    }

    cout << "Popped element from stack1 is "
        << ": " << ts.pop1() << endl;
    cout << "Popped element from stack2 is "
        << ": " << ts.pop2() << endl;
    return 0;
}
