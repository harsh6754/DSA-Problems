#include <bits/stdc++.h>
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
void print(Node *&head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        cout<< temp -> data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node *node1 = new Node(0);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;
    print(head);
    InsertAtHead(head,1);
    print(head);
    InsertAtHead(head,2);
    print(head);
    InsertAtHead(head,3);
    print(head);


    return 0;
}