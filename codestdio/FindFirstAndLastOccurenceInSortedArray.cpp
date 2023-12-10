#include<bits/stdc++.h>
using namespace std;

pair<int,int> getFirstAndLastPosition(vector<int> arr,int n,int x)
{
    int first = -1;
    int last = -1;
    for(int i = 0;i<n;i++)
    {
        if(x!=arr[i])
        {
            continue;
        }
        if(first == -1)
        {
            first = i;
        }
        last = i;
    }
    if(first!=-1)
    {
        cout<<first<<" ";
        cout<<last;
    }
}
       

int main(){
    int n;
    cout<<"Enter the size of Array"<<endl;
    cin>>n;

    int x;
    cout<<"Enter the Number You Want To find First And Last Position"<<endl;
    cin>>x;

    vector<int>arr(n);
    cout<<"Enter the Array Element"<<endl;
    for(int i = 0;i<n;i++)
    {   
       cin>>arr[i];
    }
 
    getFirstAndLastPosition(arr,n,x);
    return 0;
}