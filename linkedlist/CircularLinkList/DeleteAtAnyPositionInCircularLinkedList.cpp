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

void deleteAtHead(Node** head) {
  if (*head == nullptr) {
    cout << "List is empty. Cannot delete from an empty list." << endl;
    return;
  }

  Node* temp = *head;
  *head = (*head)->next;
  delete temp;
}

void deleteAtTail(Node** head) {
  if (*head == nullptr) {
    cout << "List is empty. Cannot delete from an empty list." << endl;
    return;
  }

  if ((*head)->next == nullptr) {
    delete *head;
    *head = nullptr;
    return;
  }

  Node* current = *head;
  while (current->next->next != nullptr) {
    current = current->next;
  }

  delete current->next;
  current->next = nullptr;
}

void deleteAtPosition(Node** head, int position) {
  if (*head == nullptr) {
    cout << "List is empty. Cannot delete from an empty list." << endl;
    return;
  }

  if (position < 0) {
    cout << "Invalid position." << endl;
    return;
  }

  if (position == 0) {
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
    return;
  }

  Node* current = *head;
  Node* prev = nullptr;
  int currentPosition = 0;

  while (currentPosition < position && current != nullptr) {
    prev = current;
    current = current->next;
    currentPosition++;
  }

  if (current == nullptr) {
    cout << "Invalid position." << endl;
    return;
  }

  prev->next = current->next;
  delete current;
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
  insertAtHead(&head, 0);
  insertAtHead(&head, 10);
  insertAtHead(&head, 20);
  insertAtHead(&head, 30);

  cout << "Original list: ";
  print(head);

  deleteAtHead(&head);
  cout << "After deleting at head: ";
  print(head);

  deleteAtTail(&head);
  cout << "After deleting at tail: ";
  print(head);

  deleteAtPosition(&head, 1);
  cout << "After deleting at position 1: ";
  print(head);

  return 0;
}
