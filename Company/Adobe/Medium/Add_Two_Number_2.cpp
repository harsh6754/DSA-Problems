#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

Node* buildList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* cur = new Node(x);
        if (!head) head = tail = cur;
        else {
            tail->next = cur;
            tail = cur;
        }
    }
    return head;
}

Node* addTwoNumbers(Node* l1, Node* l2){
    Node dummy(0);
    Node* cur = &dummy;
    int carry = 0;

    while(l1 || l2 || carry){
        int sum = carry;
        if(l1){sum+=l1->val;l1=l1->next;}
        if(l2){sum+=l2->val;l2=l2->next;}

        carry = sum/10;
        cur->next = new Node(sum%10);
        cur = cur->next;
    }
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        cout << head->val;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout << "\n";
}


int main() {
    int n, m;
    cout << "Enter size of first list: ";
    cin >> n;
    cout << "Enter size of second list: ";
    cin >> m;

    Node* list1 = buildList(n);
    Node* list2 = buildList(m);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* result = addTwoNumbers(list1,list2);
    cout<<"Sum: ";
    printList(result);

    

    return 0;
}
