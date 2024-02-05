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

  deleteAtHead(&head);
  cout << "After deleting at head: ";
  print(head);

  return 0;
}
