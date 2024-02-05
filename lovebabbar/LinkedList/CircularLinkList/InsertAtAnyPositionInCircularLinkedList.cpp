#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

void insertAtHead(Node** head, int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

void insertAtTail(Node** head, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else{
        Node* current = *head;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertAtPosition(Node** head, int data, int position) {
  if (position < 0) {
    cout << "Invalid position." << endl;
    return;
  }

  Node* newNode = new Node();
  newNode->data = data;

  if (position == 0) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  Node* current = *head;
  int currentPosition = 0;

  while (currentPosition < position - 1 && current != nullptr) {
    current = current->next;
    currentPosition++;
  }

  if (current == nullptr) {
    cout << "Invalid position." << endl;
    return;
  }

  newNode->next = current->next;
  current->next = newNode;
}

void print(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    cout << current->data << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  Node* head = nullptr;

//   insertAtHead(&head, 0);
//   print(head);

//   insertAtHead(&head, 10);
//   print(head);

//   insertAtHead(&head, 20);
//   print(head);

//   insertAtHead(&head, 30);
//   print(head);

  insertAtTail(&head,10);
  print(head);

  insertAtTail(&head,20);
  print(head);

  insertAtTail(&head,30);
  print(head);

  insertAtPosition(&head, 15,1);
  print(head);

  return 0;
}
