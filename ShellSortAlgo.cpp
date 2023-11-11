#include <iostream>  
using namespace std;  
 void shellSort(int arr[], int n) {  
     
    for (int gap = n/2; gap > 0; gap /= 2) {  
     
        for (int i = gap; i< n; i++) {  
            int temp = arr[i];  
            int j;  
            for (j = i; j >= gap &&arr[j - gap] > temp; j -= gap) {  
arr[j] = arr[j - gap];  
            }  
arr[j] = temp;  
        }  
    }  
}  
  
int main() {  
    int arr[] = {33,31,40,8,12,17,25,42};  
    int n = sizeof(arr)/sizeof(arr[0]);  
shellSort(arr, n);  
cout<< "Sorted array: ";  
    for (int i = 0; i< n; i++) {  
cout<<arr[i] << " ";  
    }  
    return 0;  
}  