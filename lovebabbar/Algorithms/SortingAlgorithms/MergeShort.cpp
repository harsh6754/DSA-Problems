#include <bits/stdc++.h>

using namespace std;

void mergeofarrays(int a[], int low, int mid, int high) {
  int i = low, j = mid + 1, index = low, temp[100], k;

  while ((i <= mid) && (j <= high)) {
    if (a[i] < a[j]) {
      temp[index] = a[i];
      i++;
    } else {
      temp[index] = a[j];
      j++;
    }
    index++;
  }

  //copy the remaining elements of right array
  if (i > mid) {
    while (j <= high) {
      temp[index] = a[j];
      j++;
      index++;
    }
  } else //remaining elements of left array
  {
    while (i <= mid) {
      temp[index] = a[i];
      i++;
      index++;
    }
  }

  for (k = low; k < index; k++) //copying into original array
  {
    a[k] = temp[k];
  }

}

void mergesort(int a[], int low, int high) {
  if (low < high) {
    int middle = (low + high) / 2; //calculating middle index of array to divide it in two halves

    mergesort(a, low, middle); //sorting first half
    mergesort(a, middle + 1, high); //sorting second half

    mergeofarrays(a, low, middle, high); //merging 2 sorted halves
  }
}

int main() {
  int n = 7;
  int a[100] = {54,34,23,10,98,2,3};
  mergesort(a, 0, 6);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}