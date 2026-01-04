#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100000;

vector<int> tree[MAXN+5];
int a[MAXN+5];
long long answer = 0;

// Convert number to square-free form
int squareFree(int x){
    for(int p = 2; p * p <= x; p++){
        int cnt = 0;
        while(x % p == 0){
            x /= p;
            cnt ^= 1; 
        }
        if(cnt) x *= p;
    }
    return x;
}

// DFS + DSU on Tree
unordered_map<int,int>* dfs(int u){
    auto *mp = new unordered_map<int,int>();
    (*mp)[a[u]]++;

    for(int v : tree[u]){
        auto *child = dfs(v);

        if(child->size() > mp->size())
            swap(child, mp);

        for(auto &p : *child){
            answer += 1LL * (*mp)[p.first] * p.second;
            (*mp)[p.first] += p.second;
        }
        delete child;
    }

    return mp;
}

int main(){
    int n;
    cin >> n;

    vector<int> parent(n+1);
    for(int i = 1; i <= n; i++){
        cin >> parent[i];
        if(i > 1) tree[parent[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = squareFree(a[i]);
    }

    dfs(1);
    cout << answer % MOD;
}
