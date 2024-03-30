#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream> // Include the <sstream> header for istringstream

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<string>> survey_responses(n);
    for (int i = 0; i < n; ++i) {
        string response;
        getline(cin >> ws, response);
        istringstream iss(response);
        string book_title;
        while (getline(iss, book_title, ',')) {
            survey_responses[i].push_back(book_title);
        }
    }

    unordered_map<string, int> book_freq;
    for (const auto& response : survey_responses) {
        for (const auto& book_title : response) {
            book_freq[book_title]++;
        }
    }

    vector<pair<string, int>> sorted_book_freq(book_freq.begin(), book_freq.end());
    sort(sorted_book_freq.begin(), sorted_book_freq.end());

    for (const auto& pair : sorted_book_freq) {
        cout << pair.first << ":" << pair.second << endl;
    }

    return 0;
}

