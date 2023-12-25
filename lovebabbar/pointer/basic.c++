#include<iostream>
using namespace std;
int main()
{
   /* int num =5;
    cout<<num<<endl;

    //data address
    cout<<&num<<endl;

    //pointer

    int *p =&num;
    num++;
    ++num;
    --num;
    num--;
    cout<<"the value is:"<<*p<<endl;
    cout<<"the value is:"<<p<<endl;


    //double pointer

    double d = 4.3;
    double *ptr = &d;

    cout<<"the value is:"<<*ptr<<endl;
    cout<<"the address is:"<<ptr<<endl;


    int arr[3]={10,20,30};
    cout<<"start"<<endl;
    int *point=arr;
    cout<<point<<" "<<*point<<endl;
    *point=*point +1;
    cout<<point<<" "<<*point<<endl;
    point =point+3;
    cout<<point<<" "<<*point<<endl;
    return 0;

    float f = 10.5;
    float p  = 2.5;
    float * ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout<<*ptr << " "<<f<<" "<<p;*/

   /* int a[] = {1, 2, 3, 4};
cout << *(a) << " " << *(a+1);*/

/*int arr[10]={0,1,2,3,4,5,6,7,8,9};
cout<<"Address of first element is"<<arr<<endl;
cout<<"Address of first element is"<<&arr[0]<<endl;
cout<<"value of first index is: "<<arr[0]<<endl;
cout<<"value of first index is: "<<*arr<<endl;
cout<<"value of first index is: "<<*arr+1<<endl;
cout<<"value of first index is: "<<*(arr + 1)<<endl;

int i = 3;
cout<<i[arr]<<endl;*/
int n = 10;
int a[n]= { 2,1,3,5,6,7,4,9,8,0};
for(int i = 0; i < n; ++i)
{ 
        cout << a[i] << " ";
}
return 0;
}