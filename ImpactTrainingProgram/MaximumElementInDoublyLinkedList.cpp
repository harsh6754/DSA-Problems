#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;
};

Node* head = NULL;

void insertAtHead(int data) {
  Node* newNode = new Node();
  newNode->data = data;
  newNode->next = head;
  newNode->prev = NULL;

  if (head != NULL) {
    head->prev = newNode;
  }

  head = newNode;
}

void printList() {
  Node* temp = head;

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

int findMax() {
  Node* temp = head;
  int max = temp->data;

  while (temp != NULL) {
    if (temp->data > max) {
      max = temp->data;
    }

    temp = temp->next;
  }

  return max;
}

void reverseList() {
  Node* current = head;
  Node *nextNode = nullptr, *prevNode = nullptr;

  while (current != nullptr) {
    nextNode = current->next;
    current->next = prevNode;
    current->prev = nextNode;
    prevNode = current;
    current = nextNode;
  }

  head = prevNode;
}

void reverseKElements(int k) {
  Node* current = head;
  Node* prevTail = nullptr;

  while (current != nullptr) {
    Node* tail = current;
    Node* prev = nullptr;

    int count = 0;

    // Reverse K elements
    while (current != nullptr && count < k) {
      Node* nextNode = current->next;
      current->next = prev;
      current->prev = nextNode;
      prev = current;
      current = nextNode;
      count++;
    }

    // Update head if reversing the first K elements
    if (prevTail == nullptr) {
      head = prev;
    } else {
      prevTail->next = prev;
    }

    tail->next = current;

    if (current != nullptr) {
      current->prev = tail;
    }

    prevTail = tail;
  }
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;

   for(int i = 0; i < n; i++)
   {
      int value;
      cout << "Enter element " << i + 1 << ": ";
      cin >> value;
      insertAtHead(value);
   }

  cout << "The original list is: ";
  printList();

  cout << "The maximum element in the list is: " << findMax() << endl;

  reverseList();

  cout << "Reverse Doubly Linked List: ";
  printList();

  int k;
  cout << "Enter the value of K for reversing elements: ";
  cin >> k;

  reverseKElements(k);

  cout << "Doubly Linked List after reversing every " << k << " elements: ";
  printList();

  return 0;
}
