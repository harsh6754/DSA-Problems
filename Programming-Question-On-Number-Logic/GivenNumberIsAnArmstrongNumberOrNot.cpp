#include<iostream>
using namespace std;

// Function to calculate the sum of cubes of digits
int add(int n)
{
    int sum = 0;
    while(n != 0)
    {
        int rem = n % 10;
        n = n / 10;
        sum = sum + rem * rem * rem;
    }
    return sum;
}

// Function to check if a number is Armstrong
bool isArmstrong(int num)
{
    int sum = add(num);
    return (sum == num);
}

int main()
{
    int num;
    cin >> num;

    if (isArmstrong(num))
        cout << "It is an Armstrong Number" << endl;
    else
        cout << "It is not an Armstrong Number" << endl;

    return 0;
}
