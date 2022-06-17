#include<bits/stdc++.h>
using namespace std;

const int N = 510;
int n, m, s, t;
bool lol[N];
double d[N];
vector<pair<int, int>> adj[N];

bool check(double x) {
    for (int i = 1; i <= n; i++) {
        d[i] = 1e8, lol[i] = false;
    }

    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int v = 1; v <= n; v++) {
            for (auto u : adj[v]) {
                if (d[u.first] < 1e8) {
                    d[v] = min(d[v], d[u.first] + (double)(u.second) - x);
                }
            }
        }
    }

    for (int v = 1; v <= n; v++) {
        for (auto u : adj[v]) {
            if (d[u.first] + (double)(u.second) - x < d[v] && d[u.first] < 1e8) {
                lol[v] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int v = 1; v <= n; v++) {
            for (auto u : adj[v]) {
                lol[v] |= lol[u.first];
            }
        }
    }

    return (d[t] >= 0.0 && lol[t] == false);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }

    for (int i = 1; i <= m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        adj[u].push_back({ v, w });
    }
    cin >> s >> t;

    double l = 0, r = 200;
    for (int i = 0; i < 100; i++) {
        double mid = (l + r) / 2.0;
        if (check(mid)) {
            l = mid;
            continue;
        }
        r = mid;
    }

    if (l < 200.0) {
        cout << l << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout << setprecision(7) << fixed;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
