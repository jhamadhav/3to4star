#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD (ll)1e9+7

void dfs(int node, vector<vector<int>>& arr, vector<int>& visited, int& cost) {
    if (visited[node]) return;

    visited[node] = 1;
    cost++;
    for (int i : arr[node]) {
        if (visited[i] == 0) {
            dfs(i, arr, visited, cost);
        }
    }
}

void solve() {
    int n, e;
    cin >> n >> e;

    vector<vector<int>> arr(n);
    for (int i = 0;i < e;++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    vector<int> res, visited(n, 0);
    for (int i = 0;i < n;++i) {
        int cost = 0;
        dfs(i, arr, visited, cost);

        if (cost != 0) {
            res.push_back(cost);
        }
    }

    ll ans = 1;
    for (int i : res) {
        ans *= i;
        ans %= MOD;
    }
    cout << res.size() << " " << ans << endl;
}

int main() {

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}