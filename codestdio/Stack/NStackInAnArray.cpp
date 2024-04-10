#include <iostream>
#include <vector>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        for (int i = 0; i < n; i++)
            top[i] = -1;
        for (int i = 0; i < s; i++)
            next[i] = i + 1;
        next[s - 1] = -1;
        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        if (freeSpot == -1 || m < 1 || m > n)
            return false;
        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = x;
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        if (m < 1 || m > n || top[m - 1] == -1)
            return -1;
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main() {
    int N, S;
    cout << "Enter the number of stacks: ";
    cin >> N;
    cout << "Enter the size of each stack: ";
    cin >> S;

    NStack myStack(N, S);

    // Example usage: Pushing elements into stacks and popping them
    myStack.push(5, 1);
    myStack.push(10, 2);
    myStack.push(15, 1);

    cout << "Popped element from stack 1: " << myStack.pop(1) << endl;
    cout << "Popped element from stack 2: " << myStack.pop(2) << endl;
    cout << "Popped element from stack 1: " << myStack.pop(1) << endl;

    return 0;
}
