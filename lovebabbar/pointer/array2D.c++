#include<iostream>
using namespace std;
int main()
{
    int arr[3][3][3]={{0,1,2},
    {3,4,5},
    {6,7,8}
    };

    for(int i = 0;i<3;i++)
    {
        for(int j = 0;j<3;j++)
        {
            for(int k = 0;k<3;k++)
            {
                arr[i][j][k] = i + j + k;
                cout<<arr[i][j][k]<<" ";
            }
        }
    }
}