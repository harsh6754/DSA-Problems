//month [3]
//per day Room Charge[1500]
//Days stay[2]
//[1,3,2,7,8,9,10] 1500*Days
//[4,5,6,11,12] 1500+20%*Days


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int amount;
    cout<<"Enter Per Day Room Amount"<<endl;
    cin>>amount;

    int days;
    cout<<"Enter How Many Days You Stay in Hotel"<<endl;
    cin>>days;

    int rent;
    cout<<"Rent in percent"<<endl;
    cin>>rent;

    


    cout<<"Hotel Rent in Specific Month"<<HotelRent(amount,rent,days)<<endl;


    return 0;
}
