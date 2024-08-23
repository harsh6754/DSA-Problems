#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    // Calculate the number of flagstones needed along the length and the width
    long long numFlagstonesAlongN = (n + a - 1) / a;
    long long numFlagstonesAlongM = (m + a - 1) / a;

    // Total number of flagstones needed
    long long totalFlagstones = numFlagstonesAlongN * numFlagstonesAlongM;

    cout << totalFlagstones << endl;

    return 0;
}
