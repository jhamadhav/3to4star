#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

#define maxn 300111
#define logN 20

vector <int> adj[maxn];
int f[maxn][logN], depth[maxn], n;

void dfs(int u) {
    for (int i = 1; i < logN; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];

    for (int i = 0; i < (int) adj[u].size(); i++) {
        int v = adj[u][i];

        if (!depth[v]) {
            f[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int lca (int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = logN - 1; i >= 0; i--)
        if (depth[f[u][i]] >= depth[v]) {
            u = f[u][i];
        }

    if (u == v) return u;

    for (int i = logN - 1; i >= 0; i--)
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }

    return f[u][0];
}

int dist (int u, int v) {
    int x = lca(u, v);
    int res = depth[u] + depth[v] - 2 * depth[x];
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 1;
    dfs(1);

    int q;
    cin >> q;

    pair<int, int> p[6];
    while (q--) {
        int u, v, r;

        cin >> r >> u >> v;

        p[0].second = u;
        p[1].second = v;
        p[2].second = r;
        p[3].second = lca(r, u);
        p[4].second = lca(r, v);
        p[5].second = lca(u, v);

        for (int i = 0; i < 6; i++) {
            int x = p[i].second;
            p[i].first = dist(x, r) + dist(x, u) + dist(x, v);
        }

        sort(p, p + 6);

        cout << p[0].second << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}