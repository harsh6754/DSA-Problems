// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int data){
//         this->data = data;
//         this->prev = NULL;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node*& head, int newData){
//     Node* temp = new Node(newData);
//     temp->next = head;
//     head->prev = temp;
//     head = temp;
// }

// void displayList(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp->data;
//         if(temp->next != NULL){
//             cout<<"<->";
//         }
//         temp = temp->next;
//     }
//     cout<<endl;
// }
// int main(){
//     Node* head = NULL;
//     int n,value;
//     cin>>n;

//     for(int i = 0;i<n;i++){
//         cout<<"Enter the Value"<<i+1<<":";
//         cin>>value;
//         insertAtHead(head,value);
//     }

//     displayList(head);

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {  // Corrected constructor syntax
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node*& head, int newData) {
    Node* temp = new Node(newData);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    head = temp;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) {
            cout << " <-> ";  // Separator between nodes
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the Value " << i + 1 << ": ";
        cin >> value;
        insertAtHead(head, value);
    }

    displayList(head);

    return 0;
}
