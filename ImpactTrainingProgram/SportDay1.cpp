#include <iostream>
#include <vector>

using namespace std;

int NoOfBeats(int n, const vector<int>& Board) {    
    vector<int> OP(n), CP(n);
    for (int i = 0; i < n; ++i) {
        OP[i] = i + 1;
        CP[i] = i + 1;
    }
    
    int Beats = 0;
    
    while (true) {
        vector<int> NP(n);
        for (int i = 0; i < n; ++i) {
            NP[i] = CP[Board[i] - 1];
        }
        
        Beats++;
        
        if (NP == OP) {
            break;
        }
        
        CP = NP;
    }
    
    return Beats;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> Board(n);
    for (int i = 0; i < n; ++i) {
        cin >> Board[i];
    }
    
    int result = NoOfBeats(n, Board);
    cout << result << endl;

    return 0;
}
