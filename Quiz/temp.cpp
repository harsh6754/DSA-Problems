#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void RotateDegree(int arr[][100], int n)
        {
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    swap(arr[i][j], arr[j][i]);
                }
            }
        
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n/2; j++) {
                    swap(arr[i][j], arr[i][n-j-1]);
                }
            }
        }
};

int main()
{
    int n;
    cin >> n;
    
    int arr[100][100];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout<<endl;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<< arr[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    
    Solution solution;
    solution.RotateDegree(arr, n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
