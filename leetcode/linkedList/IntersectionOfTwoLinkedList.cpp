#include<bits/stdc++.h>
using namespace std;
class Node{
    int val;
    ListNode* next;

    ListNode(val){
        this->val = val;
        this->next = NULL;
    }
};


int main(){
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;
    int n,value;
    cin>>n;

    for(int i = 0;i<n;i++){
        cout<<"Enter the value"<<i+1<<":";
        cin>>value;
        insertAtTail(head1,value);
    }

    for(int i = 0;i<n;i++){
        cout<<"Enter the value"<<i+1<<":";
        cin>>value;
        insertAtTail(head2,value);
    }

    Solution solution;
    ListNode* result = solution.getIntersectionNode(head1,head2);
    intersection(result);
    displayList(result);

    return 0;
}