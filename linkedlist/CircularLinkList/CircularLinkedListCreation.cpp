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


void print(Node *head) {
  Node* current = head; // Initialize current to head
  while (current != NULL) {
    cout << current->data <<" ";
    current = current->next;
  }
  cout<<endl;
}

int main() {
  Node* head = NULL;

  insertAtHead(&head, 0);
  print(head);

  insertAtHead(&head, 10);
  print(head);

  insertAtHead(&head, 20);
  print(head);

  insertAtHead(&head, 30);
  print(head);

  insertAtTail(&head,10);
  print(head);

  insertAtTail(&head,20);
  print(head);

  insertAtTail(&head,30);
  print(head);

  return 0;
}
