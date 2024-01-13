
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

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
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
    int initialData;
    cin >> initialData;

    Node *node1 = new Node(initialData);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    int newData;
    cin >> newData;
    insertAtTail(tail, newData);
    print(head);

    cin >> newData;
    insertAtTail(tail, newData);
    print(head);

    cin >> newData;
    insertAtTail(tail, newData);
    print(head);

    cin >> newData;
    insertAtTail(tail, newData);
    print(head);

    cin >> newData;
    insertAtTail(tail, newData);
    print(head);

    return 0;
}
