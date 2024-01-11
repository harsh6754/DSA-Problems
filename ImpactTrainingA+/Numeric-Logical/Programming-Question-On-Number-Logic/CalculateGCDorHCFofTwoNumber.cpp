#include<bits/stdc++.h>
using namespace std;

int GCD_HCF_Calculate(int GCD,int HCF){
    while(GCD!=HCF){
        if(GCD>HCF){
            GCD = GCD - HCF;
        }
        else{
            HCF = HCF - GCD;
        }
    }
     return HCF;
}

int main()
{
    int GCD;
    int HCF;
    cin>>GCD;
    cin>>HCF;



    cout<<GCD_HCF_Calculate(GCD,HCF)<<endl;
    return 0;
}