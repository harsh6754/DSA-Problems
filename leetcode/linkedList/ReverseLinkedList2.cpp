#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtTail(ListNode*& head, int newData) {
    ListNode* newNode = new ListNode(newData);
    if (head == NULL) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout <<" -> NULL";
}

class Solution{
    public:
    ListNode* reverseBetween(ListNode*& head, int left, int right){
        if(head == NULL || left == right){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;

        for(int i = 0;i<left - 1;i++){
            pre = pre->next;
        }
        ListNode* start = pre->next;
        ListNode* then = start->next;

        for(int i = 0;i<right - left; i++){
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }
        return dummy->next;
    }
};

int main(){
    ListNode* head = NULL;

    int n,value;
    cin>>n;

    for(int i = 0;i<n;i++){
        cout<<"Enter the value "<<i+1<<":";
        cin>>value;
        insertAtTail(head,value);
    }

    int left,right;
    cin>>left>>right;

    Solution solution;
    ListNode* result = solution.reverseBetween(head,left,right);

    displayList(head);
    return 0;
}