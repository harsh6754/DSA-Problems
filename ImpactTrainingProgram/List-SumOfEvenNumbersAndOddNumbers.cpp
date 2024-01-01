#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, num, evenSum = 0, oddSum = 0;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        if (num % 2 == 0)
        {
            evenSum += num; 
        }
        else
        {
            oddSum += num; 
        }
    }

    cout << "The sum of the even numbers in the array is " << evenSum << endl;

    cout << "The sum of the odd numbers in the array is " << oddSum << endl;

    return 0;
}
