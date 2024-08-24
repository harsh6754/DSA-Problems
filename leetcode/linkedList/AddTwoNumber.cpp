#include<bits/stdc++.h>
using namespace std;
int main(){
    ListNode* head1 = NULL;
    ListNode* head2 = NULL;

    int n,value;
    cin>>n;

    for(int i = 0;i<n;i++){
        cout<<"Enter Value of List1"<<i +1<<":";
        int value;
        insertAtTail(head1,value);
    }
    for(int i = 0;i<n;i++){
        cout<<"Enter Value of List2"<<i+1<<":";
        int value;
        insertAtTail(head2,value);
    }

    return 0;
}