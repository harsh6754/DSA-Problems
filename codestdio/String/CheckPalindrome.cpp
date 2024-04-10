#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(char ch[],int n){
    int s = 0;
    int e = n - 1;
    while(s<e){
        if(ch[s]!=ch[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;

}

void reverse(char ch[],int n)
{
    int s = 0;
    int e = n - 1;
    while(s<e){
        swap(ch[s],ch[e]);
        s++;
        e--;
    }
}


int getLength(char ch[]){
    int count = 0;
    for(int i = 0;ch[i]!='\0';i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char ch[100];
    cout<<"Enter Your Name"<<endl;
    cin>>ch;

    cout<<"Your Name is:- "<<ch<<endl;

    int len = getLength(ch);
    cout<<"Length Of String:- "<<len<<endl;

    reverse(ch,len);
    cout<<"Reverse Name  is "<<ch<<endl;

    cout<<"String is Palindrome?"<<":- "<<isPalindrome(ch,len)<<endl;

    return 0;
}