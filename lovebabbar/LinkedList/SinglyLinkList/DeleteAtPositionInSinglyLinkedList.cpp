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

void DeleteNodeAtBeginning(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty. Cannot delete from an empty list." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
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
    Node *node1 = new Node(0);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;

    print(head);

    InsertAtTail(tail, 1);
    print(head);

    InsertAtTail(tail, 2);
    print(head);

    InsertAtTail(tail, 3);
    print(head);

    InsertAtTail(tail, 5);
    print(head);

    InsertAtPosition(head, tail, 5, 4);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    DeleteNodeAtBeginning(head);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    DeleteNodeAtTail(head, tail);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    DeleteAtPosition(head, tail, 3);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    DeleteAtPosition(head, tail, 2);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    DeleteAtPosition(head, tail, 1);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    return 0;
}
