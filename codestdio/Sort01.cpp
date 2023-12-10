#include <iostream>

using namespace std;

class Solution {
public:
    void segregate0and1(int arr[], int n) {
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0)
                count++;
        }

        for (int i = 0; i < count; i++)
            arr[i] = 0;

        for (int i = count; i < n; i++)
            arr[i] = 1;
    }
};

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution ob;
    
    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    ob.segregate0and1(arr, n);

    cout << "After Sorting: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
