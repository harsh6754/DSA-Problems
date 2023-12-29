#include<bits/stdc++.h>

using namespace std;

int main() {
    // Input
    int length, breadth;
    cin >> length;
    cin >> breadth;

    // Calculate requirements
    int perimeter = 2 * (length + breadth);
    int area = length * breadth;

    // Output
    cout << "The required length is " << perimeter << " m" << endl;
    cout << "The required area of carpet is " << area << " sqm" << endl;

    return 0;
}
