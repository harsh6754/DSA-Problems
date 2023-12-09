#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>getPairSum(vector<int>arr,int n,int x){
     vector<vector<int>>ans;
     for(int i = 0;i<n;i++)
     {
        for(int j= i+1;j<n;j++)
        {
            if(arr[i]+arr[j]== x)
            {
                vector<int>temp;
                temp.push_back(min(arr[i],arr[j]));
                temp.push_back(max(arr[i],arr[j]));
                ans.push_back(temp);
            }
        }
     }
     return ans;
}


int main()
{
    int n;
    cout<<"Enter the Array Size"<<endl;
    cin>>n;

    int x;
    cout<<"Enter the Target Value"<<endl;
    cin>>x;

    vector<int>arr(n);

    cout<<"Enter Array Element"<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<vector<int>> pairs = getPairSum(arr,n,x);

    cout<<"Pair Sum is "<<endl;
     for (auto pair : pairs) {
        cout << "(" << pair[0] << ", " << pair[1] << ") ";
    }
    cout << endl;

    return 0;
}