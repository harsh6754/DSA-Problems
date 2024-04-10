#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int numPages) {
    int cntStudents = 1;
    int curSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > numPages) {
            return false;
        }
        if (curSum + arr[i] > numPages) {
        
            //Increment student count by '1'
            cntStudents += 1;
            
            //assign current book to next student and update curSum
            curSum = arr[i];
            
            //If count of students becomes greater than given no. of students, return False
            if (cntStudents > m) {
                return false;
            }
        } else {
            //Else assign this book to current student and update curSum.
            curSum += arr[i];
        }
    }
    return true;
}
int allocateBooks(int arr[], int n, int m) {
    //If number student is more than number of books.
    if (n < m) {
        return -1;
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    for (int numPages = 1; numPages <= sum; numPages++) {
        if (isPossible(arr, n, m, numPages)) {
            return numPages;
        }
    }
    return -1;
}


int main()
{
    int n;
    cout<<"Enter the Size  of array"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the Number Of Student"<<endl;
    cin>>m;

    int arr[100];
    cout<<"Enter the Array Element"<<endl;
    for(int i= 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<allocateBooks(arr,n,m);

    return 0;
}


