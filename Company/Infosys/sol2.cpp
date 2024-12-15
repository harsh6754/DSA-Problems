#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int calculate(int N, vector<int> Arr) {
    // Find the maximum height in the array
    int max_height = *max_element(Arr.begin(), Arr.end());

    // Calculate the number of buildings with the maximum height
    int max_count = count(Arr.begin(), Arr.end(), max_height);

    // Calculate the number of years required for the remaining buildings to reach the maximum height
    int years = 0;
    for (int height : Arr) {
        if (height < max_height) {
            int diff = max_height - height;
            years += (diff + 1) / 2; // Round up to the nearest integer
        }
    }

    // If all buildings are not already at the maximum height, we need at least one more year 
    // only if there are at least two buildings with less than the maximum height
    if (max_count < N && N - max_count > 1) {
        years++;
    }

    return years % MOD;
}

int main() {
    int N;
    cin >> N;

    vector<int> Arr(N);
    for (int i = 0; i < N; i++) {
        cin >> Arr[i];
    }

    int result = calculate(N, Arr);
    cout << result << endl;

    return 0;
}