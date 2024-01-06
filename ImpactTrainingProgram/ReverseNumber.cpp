#include<bits/stdc++.h>
using namespace std;

int reverseNumber(int nums)
{
    int reversed = 0;
    while (nums != 0)
    {
        int digit = nums % 10;
        reversed = reversed * 10 + digit;
        nums /= 10;
    }
    return reversed;
}

int main()
{
    int nums;
    cin >> nums;

    int result = reverseNumber(nums);

    cout << result << endl;

    return 0;
}
