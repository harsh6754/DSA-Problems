#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void insertAtHead(Node* &head,int newData){
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

void deleteAtHead(Node*& head){
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void displayList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}
int main(){
    Node* head = NULL;
    int n,value;
    cin>>n;
    for(int i = 0;i<n;i++){
         cout << "Enter value " << i + 1 << ": ";
        cin>>value;
        insertAtHead(head,value);
    }
    deleteAtHead(head);
    displayList(head);
    return 0;
}