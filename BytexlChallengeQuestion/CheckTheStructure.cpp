#include <iostream>
#include <vector>
using namespace std;

bool isValidBST(vector<int> &preorder, int start, int end)
{
    if (start >= end)  
        return true;

    int root_val = preorder[start]; 

    int right_start = start + 1;
    while (right_start < end && preorder[right_start] < root_val)
        right_start++;

    for (int i = right_start; i < end; i++)
    {
        if (preorder[i] <= root_val)
            return false;
    }
    return isValidBST(preorder, start + 1,
                      right_start) &&
           isValidBST(preorder, right_start, end);
}

string isValidBST(vector<int> &preorder)
{
    return isValidBST(preorder, 0, preorder.size()) ? "YES" : "NO";
}

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n;
        cin >> n;

        vector<int> preorder(n);
        for (int i = 0; i < n; i++)
            cin >> preorder[i];

        cout << isValidBST(preorder) << endl;
    }

     return 0;
}