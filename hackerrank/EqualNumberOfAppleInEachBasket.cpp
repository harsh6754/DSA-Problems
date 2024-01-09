#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int minApplesToMove(int N, vector<int>& apples) {
   int totalApples = accumulate(apples.begin(), apples.end(), 0);
   int equalApplesPerBasket = totalApples / N;

   int moves = 0;
   for (int count : apples) {
       moves += abs(count - equalApplesPerBasket);
   }

   return moves / 2;  // Divide by 2 to account for double-counting
}

int main() {
   int N;
   cin >> N;

   vector<int> apples(N);
   for (int i = 0; i < N; i++) {
       cin >> apples[i];
   }

   int minMoves = minApplesToMove(N, apples);
   cout << minMoves << endl;

   return 0;
}
