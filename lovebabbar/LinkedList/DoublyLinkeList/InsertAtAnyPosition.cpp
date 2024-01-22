#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    if (head != nullptr)
    {
        head->prev = temp;
    }
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail != nullptr)
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, int data, int position)
{
    Node *temp = new Node(data);
    if (position == 1)
    {
        temp->next = head;
        if (head != nullptr)
        {
            head->prev = temp;
        }
        head = temp;
    }
    else
    {
        Node *current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            temp->next = current->next;
            temp->prev = current;
            if (current->next != nullptr)
            {
                current->next->prev = temp;
            }
            current->next = temp;
        }
        else
        {
            // If position is out of bounds, you can add an error message or handle it as needed.
            cout << "Invalid position." << endl;
            delete temp; // Delete the allocated node to avoid memory leak.
        }
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(1);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(head, 2);
    print(head);

    insertAtTail(tail, 2);
    print(head);

    insertAtHead(head, 3);
    print(head);

    insertAtTail(tail, 3);
    print(head);

    insertAtPosition(head, 0, 1);
    print(head);

    insertAtPosition(tail, 4, 2);
    print(head);
    return 0;
}
