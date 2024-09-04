// C++ implementation of brute
// force solution. 
//code By Harsh
#include <bits/stdc++.h>
using namespace std;

// Function to check if the given
// number has repeated digit or not
int repeated_digit(int n)
{
	unordered_set<int> s;

 
	while(n != 0)
	{
		int d = n % 10;

	 
		if(s.find(d) != s.end())
		{
		 
			return 0;
		}
		s.insert(d);
		n = n / 10;
	}
	 
	return 1;
}

int calculate(int n,int m)
{
	int answer = 0;

	// Traversing through the range
	for(int i = n; i < m + 1; ++i)
	{

		 
		answer = answer + repeated_digit(i);
	}

	return answer ;
}

// Driver Code
int main()
{
	int n;
    cin>>n;

    int m;
    cin>>m;

	// Calling the calculate
	cout << calculate(n, m);
	return 0;
}
