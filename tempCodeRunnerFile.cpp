// A simple C++ based program to find length of longest even length
 
#include<bits/stdc++.h>
using namespace std;

int findLength(char *str)
{
	int n = strlen(str);
	int maxlen =0; // Initialize result

 
	for (int i=0; i<n; i++)
	{
		 
		for (int j =i+1; j<n; j += 2)
		{
			int length = j-i+1; 

		 
			int leftsum = 0, rightsum =0;
			for (int k =0; k<length/2; k++)
			{
				leftsum += (str[i+k]-'0');
				rightsum += (str[i+k+length/2]-'0');
			}

		 
			if (leftsum == rightsum && maxlen < length)
					maxlen = length;
		}
	}
	return maxlen;
}

 
int main(void)
{
	char str[] = "1538023";
	cout << "Length of the substring is "
		<< findLength(str);
	return 0;
}

 
