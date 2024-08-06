#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;
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
void displayList(Node *head)
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
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of nodes:" << endl;
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;

        Node *newNode = new Node{value, nullptr, nullptr};

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    displayList(head);
    deleteAtBeginning(head);
    displayList(head);

    return 0;
}
