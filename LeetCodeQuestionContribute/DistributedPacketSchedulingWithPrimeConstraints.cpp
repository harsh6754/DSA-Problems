#include <bits/stdc++.h>
using namespace std;

bool isPrime[10005];

void sieve() {
    fill(isPrime, isPrime+10005, true);
    isPrime[0] = isPrime[1] = false;
    for (int i=2; i*i<=10000; i++) {
        if (isPrime[i]) {
            for (int j=i*i; j<=10000; j+=i) isPrime[j] = false;
        }
    }
}

struct State {
    vector<int> rem;   // remaining packets per process
    int time;          // current elapsed time
    int cost;          // total latency so far
};

int minTotalLatency(int n, int k, vector<int>& p, vector<int>& t, vector<int>& d) {
    sieve();

    // initial state: all packets pending
    State start = {p, 0, 0};

    // memoization: map from (remainingPackets, time) -> minCost
    unordered_map<string, int> memo;

    auto encode = [&](const vector<int>& rem, int time) {
        string s;
        for (int x : rem) {
            s += to_string(x) + ",";
        }
        s += "#" + to_string(time);
        return s;
    };

    queue<State> q;
    q.push(start);
    memo[encode(start.rem, 0)] = 0;

    int ans = INT_MAX;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // check if done
        bool done = true;
        for (int x : cur.rem) {
            if (x > 0) { done = false; break; }
        }
        if (done) {
            ans = min(ans, cur.cost);
            continue;
        }

        // generate subsets of processes to send packets (at most k)
        vector<int> idx;
        for (int i=0; i<n; i++) if (cur.rem[i] > 0) idx.push_back(i);
        int m = idx.size();

        for (int mask=1; mask < (1<<m); mask++) {
            if (__builtin_popcount(mask) > k) continue;

            // next state
            vector<int> newRem = cur.rem;
            int maxTime = cur.time;
            bool valid = true;

            // update remaining packets and compute new time
            for (int j=0; j<m; j++) {
                if (mask & (1<<j)) {
                    int i = idx[j];
                    newRem[i]--;
                    maxTime = max(maxTime, cur.time + t[i]);
                    if (maxTime > d[i]) { valid = false; break; } // deadline miss
                }
            }
            if (!valid) continue;

            // check prime difference constraint
            vector<int> active;
            for (int j=0; j<m; j++) {
                if (mask & (1<<j)) {
                    active.push_back(newRem[idx[j]]);
                }
            }
            for (int a=0; a<active.size(); a++) {
                for (int b=a+1; b<active.size(); b++) {
                    if (!isPrime[abs(active[a]-active[b])]) valid = false;
                }
            }
            if (!valid) continue;

            int newCost = cur.cost;
            for (int j=0; j<m; j++) {
                if (mask & (1<<j)) {
                    int i = idx[j];
                    if (newRem[i] == 0) { // process finished
                        newCost += maxTime;
                    }
                }
            }

            string key = encode(newRem, maxTime);
            if (!memo.count(key) || newCost < memo[key]) {
                memo[key] = newCost;
                q.push({newRem, maxTime, newCost});
            }
        }
    }

    return ans == INT_MAX ? -1 : ans;
}

// -------------------
// Example driver code
// -------------------
int main() {
    int n = 2, k = 2;
    vector<int> p = {3, 2};
    vector<int> t = {2, 3};
    vector<int> d = {10, 9};

    cout << minTotalLatency(n, k, p, t, d) << endl; // Expected 19

    return 0;
}
