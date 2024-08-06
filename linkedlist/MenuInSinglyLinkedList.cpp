#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    {
        tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int data)
{
    if (position <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (position == 1 || head == NULL)
    {
        InsertAtHead(head, data);
        if (tail == NULL)
            tail = head; // Update tail if it's NULL
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt += 1;
    }

    if (temp == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (temp->next == NULL)
    {
        InsertAtTail(tail, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void DeleteNodeAtBeginning(Node *&head,Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    if (head == NULL)
    {
        // Update tail if the list becomes empty
        tail = NULL;
    }
}

void DeleteNodeAtTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    if (head->next == NULL)
    {
        // Only one node in the list
        delete head;
        head = tail = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    tail = temp;
}

void DeleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        if (head == NULL)
        {
            tail = NULL;
        }

        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt += 1;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;

    if (temp->next == NULL)
    {
        tail = temp;
    }

    delete nodeToDelete;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL; // Declare tail here

    int choice;
    int position, data;

    do
    {
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Insert at Position" << endl;
        cout << "4. Delete at Beginning" << endl;
        cout << "5. Delete at Tail" << endl;
        cout << "6. Delete at Position" << endl;
        cout << "7. Print List" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to insert at head: ";
            cin >> data;
            InsertAtHead(head, data);
            break;

        case 2:
            cout << "Enter data to insert at tail: ";
            cin >> data;
            InsertAtTail(tail, data);
            break;

        case 3:
            cout << "Enter position to insert: ";
            cin >> position;
            cout << "Enter data to insert at position " << position << ": ";
            cin >> data;
            InsertAtPosition(head, tail, position, data);
            break;

        case 4:
            DeleteNodeAtBeginning(head,tail);
            break;

        case 5:
            DeleteNodeAtTail(head, tail);
            break;

        case 6:
            cout << "Enter position to delete: ";
            cin >> position;
            DeleteAtPosition(head, tail, position);
            break;

        case 7:
            cout << "Current List: ";
            print(head);
            break;

        case 8:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 8);

    return 0;
}
