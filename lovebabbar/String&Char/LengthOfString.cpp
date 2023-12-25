#include<bits/stdc++.h>
using namespace std;
int getLength(char name[]){
    int count = 0;
    for(int i = 0;name[i]!='\0';i++){
        count++;
    }
    return count;
}

int main()
{
    char name[20];
    cout<<"Enter Your Name"<< endl;
    cin>>name;

    cout<<"Your Name Is :-"<< " " <<name<<endl;

    cout<<"Length Of String is :-"<<" "<<getLength(name)<<endl;
}