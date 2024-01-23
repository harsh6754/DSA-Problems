#include<bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed) {
  int n = position.size();
  vector<pair<int, int>> cars; 
  for (int i = 0; i < n; ++i) {
    cars.push_back({position[i], speed[i]});
  }

  sort(cars.begin(), cars.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
  });
  int fleets = 0;
  int slowestTime = cars[0].first / cars[0].second;
  for (auto& car : cars) {
    if (car.first <= slowestTime) {
      ++fleets;
    } else {
      slowestTime = min(slowestTime, (car.first + target - 1) / car.second); 
    }
  }

  return fleets;
}

int main() {
  int target;
  cin >> target;
  int n;
  cin >> n;
  vector<int> position(n);
  for (int i = 0; i < n; ++i) {
    cin >> position[i];
  }
  vector<int> speed(n);
  for (int i = 0; i < n; ++i) {
    cin >> speed[i];
  }
  int fleets = carFleet(target, position, speed);
  cout << fleets << endl;
  return 0;
}
