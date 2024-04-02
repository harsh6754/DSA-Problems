#include <iostream>
#include <vector>
#include <algorithm>

int min_vaccination_time(int m1, int m2, int N, std::vector<int>& villages) {
    std::sort(villages.rbegin(), villages.rend());
    int total_time_m1 = 0;
    int total_time_m2 = 0;
    for (int i = 0; i < N; i++) {
        if (total_time_m1 <= total_time_m2) {
            total_time_m1 += villages[i] * m1;
        } else {
            total_time_m2 += villages[i] * m2;
        }
    }
    return std::max(total_time_m1, total_time_m2);
}

int main() {
    int m1, m2, N;
    std::cin >> m1 >> m2 >> N;
    std::vector<int> villages(N);
    for (int i = 0; i < N; i++) {
        std::cin >> villages[i];
    }
    int min_time = min_vaccination_time(m1, m2, N, villages);
    std::cout << min_time;
    return 0;
}