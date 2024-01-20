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

    InsertAtPosition(head, tail, 5, 4);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

    return 0;
}
