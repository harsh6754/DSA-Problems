#include<bits/stdc++.h>
using namespace std;

void reverse(char ch[],int n){
    int s = 0;
    int e = n- 1;
    while(s<e){
        swap(ch[s++],ch[e--]);
    }
}


int getLength(char ch[]){
    int count = 0;
    for(int i = 0;ch[i]!='\0';i++){
        count++;
    }
    return count;
}
int main()
{
    char ch[20];
    cout<<"Enter Your Name"<<endl;
    cin>>ch;

    cout<<"Your Name is:- "<<" "<<ch<<endl;

    int length = getLength(ch);
    cout<<"Length Of String:- "<<length<<endl;

   reverse(ch,length);
   cout<<"Your Name is:- "<<" "<<ch<<endl;

    return 0;
}