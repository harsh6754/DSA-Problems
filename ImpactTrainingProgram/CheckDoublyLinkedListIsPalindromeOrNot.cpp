#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  char data;
  Node *next;
  Node *prev;

  Node(char value)
  {
    data = value;
    next = prev = NULL;
  }
};

Node *head = NULL;
Node *tail = NULL;

void insertAtLast(char data)
{

  struct Node *newNode = new Node(data);

  newNode->next = NULL;

  if (head == NULL)
  {
    newNode->prev = NULL;
    head = newNode;
    tail = newNode;
    return;
  }

  tail->next = newNode;
  newNode->prev = tail;
  tail = tail->next;
}

bool isPalindrome(Node *start)
{

  if (start == NULL)
    return true;

  Node *end = tail;

  while (start != end && end != start->prev)
  {

    if (start->data != end->data)
      return false;

    start = start->next;
    end = end->prev;
  }

  return true;
}

int main()
{

  string s = "abcba";
  cout << "Elements of Doubly Linked list : ";
  cout << s << endl;

  for (int i = 0; i < s.length(); i++)
    insertAtLast(s[i]);

  Node *start = head;
  if (isPalindrome(start))
    cout << "Yes, Doubly Linked list forms a palindrome." << endl;
  else
    cout << "No, Doubly Linked list does not form a palindrome." << endl;

  return 0;
}
