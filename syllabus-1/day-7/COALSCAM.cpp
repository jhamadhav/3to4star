#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

bool comp(pair<ll, pair<int, int>> a, pair<ll, pair<int, int>> b) {
    return a.first > b.first;
}

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
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<pair<ll, pair<int, int>>> arr1, arr2;
    for (int i = 0;i < m1;++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        arr1.push_back({ c,{a,b} });
    }

    for (int i = 0;i < m2;++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        arr2.push_back({ c,{a,b} });
    }

    // for union set operations we set the arrays
    vector<int> parent(n, 0), rank(n, 0);
    for (int i = 0;i < n;++i) {
        parent[i] = i;
    }

    // sort chef proposed roads in descending order
    sort(arr2.begin(), arr2.end(), comp);

    ll count = 0, cst1 = 0, cst2 = 0; // node count and costs for MST
    for (auto i : arr2) {
        pair<int, int> temp = i.second;
        if (unionMerge(temp.first, temp.second, parent, rank)) {
            count++;
            cst1 += i.first;
        }
    }

    // sort others in ascending order
    sort(arr1.begin(), arr1.end());
    for (auto i : arr1) {
        pair<int, int> temp = i.second;
        if (unionMerge(temp.first, temp.second, parent, rank)) {
            count++;
            cst2 += i.first;
        }
    }

    // if all nodes are not reachable then it is Impossible
    if (count != n - 1) {
        cout << "Impossible" << endl;
        return;
    }
    cout << cst1 << " " << (ll)(cst1 + cst2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}