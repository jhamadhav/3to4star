#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void solve() {
    ll n, e, k;
    cin >> n >> e >> k;

    vector<vector<pair<ll, ll>>> arr(n);
    for (ll i = 0; i < e; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;
        arr[a].push_back({ b,c });
        arr[b].push_back({ a,c });
    }

    // we will start by giving node 0 value 0; 
    vector<ll> val(n, -1);
    vector<ll> component(n, -1);

    // using bfs travel, we need {node, parentNodeValue}
    ll lc = 0;
    for (int i = 0;i < n;++i) {
        if (val[i] != -1) continue;

        val[i] = 0;
        component[i] = i;
        lc = i;

        queue<pair<ll, ll>> q;
        q.push({ i,-1 });

        while (q.empty() == false) {
            ll len = q.size();
            while (len--) {
                pair<ll, ll> temp = q.front();
                q.pop();

                ll node = temp.first;
                ll pVal = temp.second;

                if (val[node] == pVal) continue;

                if (val[node] == -1) {
                    val[node] = pVal;
                }

                if (val[node] != pVal && pVal != -1) {
                    cout << -1 << endl;
                    return;
                }

                if (component[node] == -1) {
                    component[node] = lc;
                }

                for (auto j : arr[node]) {
                    ll nodeVal = (ll)val[node] ^ j.second;
                    q.push({ j.first,nodeVal });
                }
            }
        }
    }

    for (ll i = 0;i < val.size();++i) {
        if (component[i] == component[lc]) {
            val[i] = val[i] ^ (k - 1);
        }
        cout << val[i] << " ";
    }
}

int main() {

    solve();

    return 0;
}