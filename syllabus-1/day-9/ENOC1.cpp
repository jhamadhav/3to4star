#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const ll MAX = 1e5 + 10, LOG = 20;

vector<ll> G[MAX];
vector<ll> lvl(MAX), val;
vector<vector<ll>> up(MAX, vector<ll>(LOG + 1)), dp(MAX, vector<ll>(LOG + 1));

void dfs(ll u, ll par, ll v = -1, ll h = 0) {
    lvl[u] = h;
    up[u][0] = par;
    if (v != -1)dp[u][0] = v;
    for (ll i = 1;i <= LOG;++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
        dp[u][i] = (dp[u][i - 1] ^ dp[up[u][i - 1]][i - 1]);
    }
    for (auto x : G[u]) {
        if (x != par) dfs(x, u, val[x], h + 1);
    }
}

ll lca(ll u, ll v) {
    if (lvl[u] < lvl[v])
        swap(u, v);

    for (ll i = LOG; i >= 0; --i) {
        if (lvl[up[u][i]] >= lvl[v]) {
            u = up[u][i];
        }
    }

    if (u == v) return u;

    for (ll i = LOG; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}


ll get(ll u, ll v) { // assumes u is at a level >= level of v
    if (u == v)
        return 0;
    ll res = 0;
    for (ll i = LOG; i >= 0; --i) {
        if (lvl[up[u][i]] >= lvl[v]) {
            res ^= dp[u][i];
            u = up[u][i];
        }
    }
    return res;
}

ll slv(ll u, ll v) {
    ll res;
    ll l = lca(u, v);
    if (l == u)
        return (get(v, l) ^ val[u]);
    if (l == v)
        return (get(u, l) ^ val[v]);
    ll p = get(u, l), q = get(v, l);
    res = (p ^ q ^ val[l]);
    return res;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    val.assign(n + 1, 0);
    for (int i = 1;i <= n;++i) {
        cin >> val[i];
    }

    for (ll i = 1;i < n;++i) {
        ll u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }


    // clear
    for (ll i = 0;i <= n;++i) {
        for (ll j = 0;j <= LOG;++j) {
            dp[i][j] = 0;
            up[i][j] = 0;
        }
    }

    dfs(1, 1);

    while (q--) {
        ll u, v;
        cin >> u >> v;
        ll res = slv(u, v);
        cout << res << endl;
    }

    for (ll i = 0;i < MAX;++i) {
        G[i].clear();
    }

}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}