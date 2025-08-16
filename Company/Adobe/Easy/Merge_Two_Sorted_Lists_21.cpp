#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
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

Node* mergeLists(Node* l1, Node* l2){
    Node dummy(0);
    Node* cur = &dummy;

    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next=l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            l2=l2->next;
        }
        cur=cur->next;
    }
    if(l1) cur->next = l1;
    else cur->next=l2;

    return dummy.next;
}


int main(){
    int n, m;
    cout<<"Enter size of first list : ";
    cin>>n;

    cout<<"Enter size of second list : ";
    cin>>m;

    Node* list1 = buildList(n);
    Node* list2 = buildList(m);

    cout<<"List 1: ";
    printList(list1);

    cout<<"List 2: ";
    printList(list2);


    Node* result = mergeLists(list1,list2);
    cout<<"Merged List : ";
    printList(result);

    return 0;
}