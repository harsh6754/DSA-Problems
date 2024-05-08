
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// float maximumGap(vector<float>& finish_times) {
//     int n = finish_times.size();
//     if (n < 2) return 0.0;

//     float min_time = *min_element(finish_times.begin(), finish_times.end());
//     float max_time = *max_element(finish_times.begin(), finish_times.end());

//     int num_buckets = n;

//     float bucket_size = (max_time - min_time) / num_buckets;

//     vector<float> buckets[num_buckets];

//     for (int i = 0; i < n; i++) {
//         int index = (finish_times[i] - min_time) / bucket_size;
//         buckets[index].push_back(finish_times[i]);
//     }
 
//     float max_gap = 0.0;
//     float prev_max = min_time;

//     for (int i = 0; i < num_buckets; i++) {
//         if (!buckets[i].empty()) {
//             float curr_min = *min_element(buckets[i].begin(), buckets[i].end());
//             max_gap = std::max(max_gap, curr_min - prev_max);
//             prev_max = *max_element(buckets[i].begin(), buckets[i].end());
//         }
//     }

//     return max_gap;
// }

// int main() {
//     vector<float> finish_times;
//     string input;
//     while (true) {
//         cin >> input;
//         if (input == "done")
//             break;
//         float time = stof(input);
//         finish_times.push_back(time);
//     }
//     float max_time_gap = maximumGap(finish_times);

//     cout << fixed;
//     cout.precision(1);
//     cout << max_time_gap << " seconds" << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

float maximumGap(const vector<float>& finish_times) {
    int n = finish_times.size();
    if (n < 2) return 0.0;

    float min_time = *min_element(finish_times.cbegin(), finish_times.cend());
    float max_time = *max_element(finish_times.cbegin(), finish_times.cend());

    int num_buckets = n;

    float bucket_size = (max_time - min_time) / num_buckets;

    unordered_map<float, vector<float>> buckets;

    for (int i = 0; i < n; i++) {
        float index = (finish_times[i] - min_time) / bucket_size;
        buckets[index].push_back(finish_times[i]);
    }

    float max_gap = 0.0;
    float prev_max = min_time;

    for (const auto& bucket : buckets) {
        if (!bucket.second.empty()) {
            float curr_min = *min_element(bucket.second.cbegin(), bucket.second.cend());
            max_gap = max(max_gap, curr_min - prev_max);
            prev_max = *max_element(bucket.second.cbegin(), bucket.second.cend());
        }
    }

    return max_gap;
}
int main() {
    vector<float> finish_times;
    string input;
    while (true) {
        cin >> input;
        if (input == "done")
            break;
        float time = stof(input);
        finish_times.push_back(time);
    }
    float max_time_gap = maximumGap(finish_times);

    cout << fixed;
    cout.precision(1);
    cout << max_time_gap << " seconds" << endl;

    return 0;
}
