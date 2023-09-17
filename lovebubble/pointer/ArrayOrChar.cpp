#include<iostream>
using namespace std;
void print(int *p){
    cout<<*p<<endl;
}

void update(int *p)
{
    //p = p+1;
    //cout<<"inside update values: "<<p<<endl;
    *p = *p + 1;
    cout<<"Update Values inside: "<<*p<<endl;
}

int getSum(int *arr,int n)
{
    cout<<endl<<"Size:"<<sizeof(arr)<<endl;
    int Sum = 0;
    for(int i = 0;i<n;i++)
    {
        Sum+=arr[i];
    }
    return Sum;
}

int main()
{

   /*int arr[5]= { 0,1,2,3,4};
    char ch[6] = "abcde";

    cout<<arr<<endl;
    cout<<ch<<endl;

    char * c = &ch[0];
    cout<<c <<endl;

    char temp ='z';
    char*p=&temp;
    cout<<p<<endl;
*/  

int value=5;
int *p =&value;
print(p);
cout<<"befor update :"<<*p<<endl;
update(p);
cout<<"After Update :"<<*p<<endl;

int arr[5] = { 1,2,3,4,5};
cout<<"Sum is"<<getSum(arr,5)<<endl;
return 0;
}