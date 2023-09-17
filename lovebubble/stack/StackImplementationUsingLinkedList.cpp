#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
    Node(int n)
    {
        data = n;
        link = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (!temp)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        temp->link = top;
        top = temp;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int peek()
    {
        if (!isEmpty())
            return top->data;
        else
        {
            cout << "Stack is empty" << endl;
            exit(1);
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->link;
        delete temp;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data;
            temp = temp->link;
            if (temp != nullptr)
                cout << " -> ";
        }
        cout << endl;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    Stack s;

    s.push(12);
    s.push(13);
    s.push(14);
    s.push(20);
    s.push(25);

    cout << "Stack elements: ";
    s.display();

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();

    cout << "Stack elements after popping two: ";
    s.display();

    cout << "Top Element is: " << s.peek() << endl;

    return 0;
}
