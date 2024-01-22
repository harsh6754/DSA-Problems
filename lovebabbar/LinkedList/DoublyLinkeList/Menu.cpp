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

void deleteAtBeginning(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    Node *temp = head;
    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    cout << "Node deleted from the beginning successfully." << endl;
}

void deleteAtEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    if (temp->prev == nullptr)
    {
        delete temp;
        head = nullptr;
    }
    else
    {
        temp->prev->next = nullptr;
        delete temp;
    }

    cout << "Node deleted from the end successfully." << endl;
}

void deleteAtPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position && temp != nullptr; ++i)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Invalid position. Node not found." << endl;
        return;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node deleted from position " << position << " successfully." << endl;
}

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
            cout << "Invalid position." << endl;
            delete temp;
        }
    }
}

void print(Node *head)
{
    cout << "Doubly Linked List: ";
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int choice = 0;
    while (choice != 8)
    {
        cout << "Choose an operation:" << endl;
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Print List\n";
        cout << "8. Exit\n";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            insertAtHead(head, data);
            break;
        }
        case 2:
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            insertAtTail(tail, data);
            break;
        }
        case 3:
        {
            int data, position;
            cout << "Enter data: ";
            cin >> data;
            cout << "Enter position: ";
            cin >> position;
            insertAtPosition(head, data, position);
            break;
        }
        case 4:
            deleteAtBeginning(head);
            break;
        case 5:
            deleteAtEnd(head);
            break;
        case 6:
        {
            int position;
            cout << "Enter position: ";
            cin >> position;
            deleteAtPosition(head, position);
            break;
        }
        case 7:
            print(head);
            break;
        case 8:
            // Exit the loop and end the program
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
