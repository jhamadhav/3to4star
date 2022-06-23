#include<bits/stdc++.h>
using namespace std;

# define ll long long int
#define endl "\n"

const int maxn = 5e5 + 10, LOG = 20;

vector<int> g[maxn];
bool visit[maxn];
int depth[maxn], parent[maxn][LOG], subsize[maxn];
ll subdist[maxn], totdist[maxn];

int n, q;
bool isGraph(int u, int pa) {
    parent[u][0] = pa;
    subsize[u] = 1;
    subdist[u] = 0;

    if (visit[u])   return false;

    visit[u] = true;
    for (int v : g[u]) {
        if (v == pa)    continue;

        depth[v] = depth[u] + 1;

        if (isGraph(v, u) == false) return false;

        subsize[u] += subsize[v];
        subdist[u] += subdist[v] + subsize[v];
    }
    return true;
}

void dfs(int u, int pa) {
    for (int v : g[u]) {
        if (v == pa)    continue;
        totdist[v] = totdist[u] - 2 * subsize[v] + n;
        //subdist[v] + totdist[u] - subdist[v] - subsize[v] + n - subsize[v]
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (u == v) return u;

    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v)return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i]; v = parent[v][i];
        }
    }
    return parent[u][0];
}

void solve() {

    cin >> n >> q;
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        visit[i] = false;
    }

    int u, v;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth[1] = 0;
    isGraph(1, 0);

    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }

    totdist[1] = subdist[1];
    dfs(1, 0);

    while (q--) {
        cin >> u >> v;

        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int dist = depth[u] + depth[v] - 2 * depth[lca(u, v)];
        int jump = (dist - 1) / 2;

        int pa1 = u, pa2; // breaking edge
        for (int i = LOG - 1; i >= 0; i--) {
            if (jump - (1 << i) >= 0) {
                jump -= (1 << i);
                pa1 = parent[pa1][i];
            }
        }
        pa2 = parent[pa1][0];
        // u
        ll ans = totdist[u] - (totdist[pa2] - (subdist[pa1] + subsize[pa1]) + (ll)(n - subsize[pa1]) * ((dist + 1) / 2));
        // v
        ans += totdist[v] - (subdist[pa1] + (ll)subsize[pa1] * (dist - (dist - 1) / 2));

        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    int tn = 0, tq = 0;
    while (t--) {
        solve();
    }
}