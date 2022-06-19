#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int findParent(int num, vector<int>& parent) {
    if (parent[num] == num) return num;
    parent[num] = findParent(parent[num], parent);
    return parent[num];
}

bool unionMerge(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);

    if (u == v) return 0; // we find cycle

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else {
        parent[v] = u;
    }

    if (rank[u] == rank[v]) {
        rank[u]++;
    }

    return 1;
}


void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<ll, pair<int, int>>> arr;
    for (int i = 0;i < m;++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;

        arr.push_back({ c,{a,b} });
    }


    // for union set operations we set the arrays
    vector<int> parent(n, 0), rank(n, 0);
    for (int i = 0;i < n;++i) {
        parent[i] = i;
    }

    // edges needed for MST 
    list<pair<ll, pair<int, int>>> mstArr;

    // kruskal to find MST
    ll cst = 0;
    sort(arr.begin(), arr.end());
    for (auto i : arr) {
        pair<int, int> temp = i.second;
        if (unionMerge(temp.first, temp.second, parent, rank)) {
            cst += i.first;
            mstArr.push_back(i);
        }
    }

    while (q--) {
        int ty;
        cin >> ty;

        if (ty == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            mstArr.push_front({ 0,{u,v} });
        }
        else if (ty == 2) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;

            for (auto i : mstArr) {
                pair<int, int> temp = i.second;
                if (temp.first == u && temp.second == v && i.first == 0) {
                    mstArr.remove(i);
                    break;
                }
            }
        }
        else {
            for (int i = 0;i < n;++i) {
                parent[i] = i;
                rank[i] = 0;
            }

            // kruskal to find MST
            ll mst = 0;
            for (auto i : mstArr) {
                pair<int, int> temp = i.second;
                if (unionMerge(temp.first, temp.second, parent, rank)) {
                    mst += i.first;
                }
            }
            cout << mst << endl;
        }
    }
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