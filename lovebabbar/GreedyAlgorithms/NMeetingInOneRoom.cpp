#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings(n);
        for (int i = 0; i < n; i++) {
            meetings[i] = {end[i], start[i]};
        }
        sort(meetings.begin(), meetings.end());
        int count = 1;
        int last_meeting_end = meetings[0].first;
        for (int i = 1; i < n; i++) {
            if (meetings[i].second > last_meeting_end) {
                count++;
                last_meeting_end = meetings[i].first;
            }
        }
        return count;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> start(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }
    vector<int> end(n);
    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }
    Solution solution;
    int result = solution.maxMeetings(start, end);
    cout << result << endl;
    return 0;
}
