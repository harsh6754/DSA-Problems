#include<iostream>
using namespace std;
void update(int **p){
    //p = p+1;
   // *p = *p + 1;
    **p = **p + 1;
}
int main()
{
    int i = 5;
    int *p =&i;
    int **p2 = &p;

    cout<<endl<<endl<<"Its All Right"<<endl<<endl;

    cout<<i<<endl;
    cout<<p<<endl;
    cout<<p2<<endl;

    update(p2);

    cout<<i<<endl;
    cout<<p<<endl;
    cout<<p2<<endl;

    cout<<endl<<endl;

    int first = 8;
    int second= 18;

    int *ptr=&second;
    *ptr=9;
    cout<<first<<" "<<second<<endl;

    

    return 0;
}