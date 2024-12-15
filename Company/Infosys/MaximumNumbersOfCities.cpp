#include <iostream>
#include <vector>

using namespace std;

int calculate(int N, vector<int> P) {
  long long total_profit = 0;
  int cities_visited = 0;

  for (int i = 0; i < N; ++i) {
    total_profit += P[i];
    if (total_profit < 0) {
      break;
    } else if (total_profit > 0) {
      cities_visited++;
    }
  }
  return cities_visited;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N;
  cin >> N;

  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }

  cout << calculate(N, P) << endl;
  return 0;
}