#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void printTwoElements(int arr[], int n)
{
	int repeatingNumber = -1;
	int missingNumber = -1;

	for (int i = 0; i < n; i++)
	{
		int index = abs(arr[i]) - 1;
		if (arr[index] > 0)
		{
			arr[index] = -arr[index]; // Mark as visited by making it negative
		}
		else
		{
			repeatingNumber = abs(arr[i]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > 0)
		{
			missingNumber = i + 1;
			break;
		}
	}

	cout << "The repeating number is " << repeatingNumber << "." << endl;
	cout << "The missing number is " << missingNumber << "." << endl;
}

int main()
{
	int arr[] = {7, 3, 4, 5, 5, 6, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	printTwoElements(arr, n);
	return 0;
}
