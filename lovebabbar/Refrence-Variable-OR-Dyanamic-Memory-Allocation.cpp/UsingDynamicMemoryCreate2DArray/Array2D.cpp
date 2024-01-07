// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     int m;
//     cin>>n;
//     cin>>m;

//     int **arr = new int *arr[n];
//     for(int i = 0;i<n;i++)
//     {
//         arr[i] = new int[n];
//     }

//     int **arr = new int *arr[m];
//     for(int j = 0;j<m;j++)
//     {
//         arr[j] = new int[m];
//     }

//     for(int i = 0;i<n;i++)
//     {
//         for(int j = 0;j<m;j++)
//         {
//             cin>>arr[i][j];
//         }
//     }

//     cout<<endl;

//     for(int i = 0;i<n;i++)
//     {
//         for(int j = 0;j<m;j++)
//         {
//             cout<<arr[i][j]<< " ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Create a 2D array with dimensions n x m
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }

    // Input values into the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Output the array
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory for the array
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
