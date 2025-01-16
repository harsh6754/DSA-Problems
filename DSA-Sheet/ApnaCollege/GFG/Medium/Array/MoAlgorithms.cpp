#include <bits/stdc++.h>
using namespace std;

struct Query {
    int L, R;
};

void printQuerySums(int a[], int n, Query q[], int m) {
    for (int i = 0; i < m; i++) {
        int L = q[i].L, R = q[i].R;
        int sum = 0;
        for (int j = L; j <= R; j++)
            sum += a[j];
        cout << "Sum of [" << L << ", " << R << "] is " << sum << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cout << "Enter the number of queries: ";
    cin >> m;
    Query q[m];
    cout << "Enter the queries (L and R): " << endl;
    for (int i = 0; i < m; i++)
        cin >> q[i].L >> q[i].R;

    printQuerySums(a, n, q, m);
    return 0;
}
