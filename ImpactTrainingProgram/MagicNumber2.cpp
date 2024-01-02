// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// bool checkFun(int X, int A, int N, int Z) {
//     int val = A * N + Z;
//     if(val == X) {
//         return 1;
//     } else {
//         return 0;
//     }
// }

// vector<int> findDivisor(int val) {
//     vector<int> ans;
//     for(int i = 1; i<=val; i++) {
//         if((val % i) == 0) {
//             ans.push_back(i);
//         } 
//     }
    
//     return ans;
// }

// void findAllPossibleOutput(int X, int A) {
//     bool flag = 1;
//     for(int i = 1; i<=X;  i++) {
//         vector<int> vec = findDivisor(i);
        
//         for(auto z : vec) {
//             if(checkFun(X, A, i , z)) {
//                 flag = 0;
//                 cout<<i<<" ";
//             }
//         }
//     }
    
//     if(flag) {
//         cout<<"None";   
//     }
// }

// int main() {
//     int A, X;
//     cin>>X>>A;
    
//     if(A > X || A < 1 || X < 1 || X > 1000000) {
//         cout<<"None";
//     }else {
//         findAllPossibleOutput(X, A);
//     }
    
    
    
//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

bool checkFun(int X, int A, int N, int Z) {
    int val = A * N + Z;
    return val == X;
}

vector<int> findDivisor(int val) {
    vector<int> ans;
    for (int i = 1; i <= val; i++) {
        if (val % i == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

void findAllPossibleOutput(int X, int A) {
    bool flag = true;
    for (int i = 1; i <= X; i++) {
        vector<int> divisors = findDivisor(i);

        for (auto z : divisors) {
            if (checkFun(X, A, i, z)) {
                flag = false;
                cout << i;
                return;  // Exit the function once a valid pair is found
            }
        }
    }

    if (flag) {
        cout << "None";
    }
}

int main() {
    int A, X;
    cin >> X >> A;

    if (A > X || A < 1 || X < 1 || X > 1000000) {
        cout << "None";
    } else {
        findAllPossibleOutput(X, A);
    }

    return 0;
}
