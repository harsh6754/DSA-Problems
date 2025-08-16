#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int v) : val(v),next(nullptr){}
};

Node* buildList(int n){
    Node* head = nullptr;
    Node* tail = nullptr;

    cout<<"Enter "<<n<<" values: ";
    for(int i = 0;i<n;i++){
        int x;
        cin>>x;
        Node* curr = new Node(x);
        if(!head) head = tail = curr;
        else{
            tail->next=curr;
            tail = curr;
        }
    }
    return head;
}

void printList(Node* head){
    while(head){
        cout<<head->val;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout<<"\n";
}

Node* deleteDuplicates(Node* head){
    Node* curr = head;
    while(curr && curr->next){
        if(curr->val == curr->next->val){
            curr->next = curr->next->next;
        }else{
            curr = curr->next;
        }
    }
    return head;
}

int main(){
    int n;
    cout<<"Enter the Length of LinkedList : ";
    cin>>n;

    Node* List = buildList(n);
    printList(List);

    Node* result = deleteDuplicates(List);
    printList(result);

    return 0;
}