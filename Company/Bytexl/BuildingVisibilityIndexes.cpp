#include<bits/stdc++.h>
using namespace std;

vector<int> findVisibleBuildings(const vector<int>& heights) {
    vector<int> visibleBuildings;
    int maxHeight = 0;

    for (int i = 0; i < heights.size(); ++i) {
        if (heights[i] > maxHeight) {
            visibleBuildings.push_back(i);
            maxHeight = heights[i];
        }
    }

    return visibleBuildings;
}

int main() {
    string input;
    vector<int> heights;
    getline(cin, input);

    // Remove '[' and ']' characters
    input.erase(remove(input.begin(), input.end(), '['), input.end());
    input.erase(remove(input.begin(), input.end(), ']'), input.end());

    stringstream ss(input);
    string heightStr;
    while (getline(ss, heightStr, ',')) {
        try {
            int height = stoi(heightStr);
            heights.push_back(height);
        } catch (invalid_argument const& e) {
            cout << "Please enter valid integer input for all building heights." << endl;
            return 1;
        } catch (out_of_range const& e) {
            cout << "Input out of range." << endl;
            return 1;
        }
    }

    vector<int> visibleBuildings = findVisibleBuildings(heights);

    cout << "[";
    for (int i = 0; i < visibleBuildings.size(); ++i) {
        cout << visibleBuildings[i];
        if (i < visibleBuildings.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
