#include <bits/stdc++.h>
using namespace std;

int n, q, sz, depth[100010], dis[100010], ans[100010], par[20][100010], f[20][100010];
vector<pair<int, int> > v[100010];
pair<pair<int, int>, pair<int, int> > qry[100010];

inline void dfs(int u, int pr, int dist, int num)
{
    par[0][u] = pr;
    depth[u] = dist;
    dis[u] = num;
    for (int i = 0;i < v[u].size();i++) {
        if (v[u][i].first != pr) dfs(v[u][i].first, u, dist + 1, num + v[u][i].second);
    }
}

inline void init()
{
    dfs(1, -1, 0, 0);
    for (int k = 0;k + 1 < 20;k++) {
        for (int i = 1;i <= n;i++) {
            if (par[k][i] < 0) par[k + 1][i] = -1;
            else par[k + 1][i] = par[k][par[k][i]];
        }
    }
}

inline int lca(int u, int v)
{
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0;k < 20;k++) {
        if (((depth[v] - depth[u]) >> k) & 1) {
            v = par[k][v];
        }
    }
    if (u == v) return u;
    for (int k = 20 - 1;k >= 0;k--) {
        if (par[k][u] != par[k][v]) {
            u = par[k][u];v = par[k][v];
        }
    }
    return par[0][u];
}

inline int jump2(int u, int p)
{
    int len = dis[u];
    for (int i = 20 - 1;i >= 0;i--) {
        if (par[i][u] != -1 && len - dis[par[i][u]] <= p) {
            u = par[i][u];
        }
    }
    return u;
}

inline pair<int, int> calc2(int u, int v, int p)
{
    int ret = 0;
    while (dis[u] - dis[v] >= p) {
        u = jump2(u, p);
        ret++;
    }
    return make_pair(ret, dis[u] - dis[v]);
}

inline int solve2(int u, int v, int p)
{
    int l = lca(u, v);
    pair<int, int> r1 = calc2(u, l, p), r2 = calc2(v, l, p);
    int res = r1.first + r2.first;
    if (r1.second + r2.second == 0);
    else if (r1.second + r2.second <= p) res++;
    else res += 2;
    return res;
}

inline pair<int, int> calc1(int u, int v, int p)
{
    int ret = 0;
    for (int i = 20 - 1;i >= 0;i--) {
        if (f[i][u] != -1 && dis[f[i][u]] > dis[v]) {
            u = f[i][u];
            ret += (1 << i);
        }
    }
    return make_pair(ret, dis[u] - dis[v]);
}

inline int solve1(int u, int v, int p)
{
    int l = lca(u, v);
    pair<int, int> r1 = calc1(u, l, p), r2 = calc1(v, l, p);
    int res = r1.first + r2.first;
    if (r1.second + r2.second == 0);
    else if (r1.second + r2.second <= p) res++;
    else res += 2;
    return res;
}

int main()
{

    ios::sync_with_stdio(false);
    cin >> n;
    sz = (int)(sqrt(n));
    for (int i = 1;i < n;i++) {
        int x, y, c;cin >> x >> y >> c;
        v[x].push_back(make_pair(y, c));
        v[y].push_back(make_pair(x, c));
    }
    init();
    cin >> q;
    for (int i = 1;i <= q;i++) {
        cin >> qry[i].second.first >> qry[i].second.second >> qry[i].first.first;
        qry[i].first.second = i;
    }
    sort(qry + 1, qry + q + 1);
    int pos = 1;
    for (int i = 1;i <= n;i++) f[0][i] = par[0][i];
    for (int i = 2;i <= sz;i++) {
        for (int j = 1;j <= n;j++) {
            if (f[0][j] != -1 && par[0][f[0][j]] != -1 && dis[j] - dis[par[0][f[0][j]]] <= i) f[0][j] = par[0][f[0][j]];
        }
        for (int j = 0;j + 1 < 20;j++) {
            for (int k = 1;k <= n;k++) {
                if (f[j][k] < 0) f[j + 1][k] = -1;
                else f[j + 1][k] = f[j][f[j][k]];
            }
        }
        for (;pos <= q && qry[pos].first.first == i;pos++) {
            ans[qry[pos].first.second] = solve1(qry[pos].second.first, qry[pos].second.second, qry[pos].first.first);
        }
    }
    for (int i = pos;i <= q;i++) {
        ans[qry[i].first.second] = solve2(qry[i].second.first, qry[i].second.second, qry[i].first.first);
    }
    for (int i = 1;i <= q;i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}


