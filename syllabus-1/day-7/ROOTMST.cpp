#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const int MAXN = (1 << 20);

struct edge {
    int u, v, w;
    edge() { u = v = w = 0; }
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};

edge e[MAXN];

int n, m;
int64_t sum;
int val[MAXN];
bool used[MAXN];
int64_t answer[MAXN];

set<pair<int, pair<int, int> > > edge_values;

int par[MAXN];
int root(int x) {
    return par[x] == x ? x : (par[x] = root(par[x]));
}

void solve() {
    sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        e[i] = edge(u, v, w);

        if (u == 1) {
            sum += w;
            val[v] = w;
        }
    }


    for (int i = 0; i < m; i++) {
        if (e[i].u != 1) {
            edge_values.insert({ e[i].w - val[e[i].u], {i, e[i].u} });
            edge_values.insert({ e[i].w - val[e[i].v], {i, e[i].v} });
        }
    }

    answer[n - 1] = sum;
    for (int i = n - 2; i >= 1; i--) {
        while (true) {
            auto it = edge_values.begin();
            int w = it->first, i = it->second.first, v = it->second.second;
            edge_values.erase(it);

            if (used[i]) {
                continue;
            }

            if (root(v) != v) {
                edge_values.insert({ e[i].w - val[root(v)], {i, root(v)} });
                continue;
            }

            if (root(e[i].u) == root(e[i].v)) {
                continue;
            }

            int u = root(e[i].u) == v ? root(e[i].v) : root(e[i].u);

            sum += w;
            par[v] = u;
            used[i] = true;
            break;
        }

        answer[i] = sum;
    }

    for (int i = 1; i <= n - 1; i++) {
        cout << answer[i] << " ";
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}