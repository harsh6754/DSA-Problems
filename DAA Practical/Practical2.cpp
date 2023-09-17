#include <iostream>
#include <algorithm>
# define Z 30

using namespace std;

void displayArr(int arr[], int n ) {
   for( int i = 0; i < n; i++ ){
      cout << arr[ i ] << ", ";
   } 
   cout << endl;
} 

int getSecondLargest( int A[], int n ){
   sort( A, A + n, greater<int>() );
   return A[ 1 ];
}

int main() {
   int arr[ Z ] = {84, 56, 21, 32, 74, 96, 85, 41, 21, 94, 20, 37, 36, 75, 20};
   int n = 15;
   
   cout << "Given array elements: ";
   displayArr( arr, n);
   
   cout << "The second largest element: " << getSecondLargest( arr, n ); 
}