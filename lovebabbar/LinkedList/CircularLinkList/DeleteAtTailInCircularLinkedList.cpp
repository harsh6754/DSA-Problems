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
  insertAtHead(&head, 10);
  insertAtHead(&head, 20);
  insertAtHead(&head, 30);

  cout << "Original list: ";
  print(head);



  deleteAtTail(&head);
  cout << "After deleting at tail: ";
  print(head);


  return 0;
}
