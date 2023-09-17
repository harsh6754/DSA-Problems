#include <iostream>
#include<vector>
vector<int> productPuzzle(vector<int> &arr, int n)
{
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int prod = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                continue;
            }
            prod *= arr[i];
        }
        ans[i] = prod;
    }
    return ans;
}

int main(){
    vector<int>arr;

}
