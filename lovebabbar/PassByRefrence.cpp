//============================================PASS BY REFRENCE=================================================== //
#include<iostream>
using namespace std;

                   //Bad Practice//
                   int &func(int a)
                {
                    int num =a;
                    int &ans = num;
                    return ans;
                }
                    //bad practice//
int update2(int&n)
{
    n++;
}

int update(int n)
{
    n++;
};
int main()
{
    // int i = 5;
    // int &j = i;
    // cout<<i<<endl;
    // i+=1;
    // cout<<i<<endl;
    // j+=1;
    // cout<<i<<endl;
    // cout<<j<<endl;

int n;
n=5;
cout<<"Befor Update:"<<n<<endl;
update(n);
cout<<"After Update : "<<n<<endl;

cout<<endl;
cout<<"After Update:"<<n<<endl;
update2(n);
cout<<"Before Update: "<<n<<endl;

func(n);

return 0;


}