#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void solve() {
    int n, e;
    cin >> n >> e;

    vector<ll> nodeVal(n);
    for (int i = 0;i < n;++i) {
        cin >> nodeVal[i];
    }

    map<ll, vector<pair<int, int>>> arr;
    for (int i = 0;i < e;++i) {
        int a, b;
        cin >> a >> b;
        a--;    b--;
        ll num = abs(nodeVal[b] - nodeVal[a]);
        if (num == 0) continue;
        if (nodeVal[b] >= nodeVal[a]) {
            arr[num].push_back({ a,b });
        }
        else {
            arr[num].push_back({ b,a });
        }
    }

    vector<int> dp(n, 0), temp(n, 0);
    for (auto j : arr) {
        for (auto k : j.second) {
            temp[k.second] = 0;
        }
        for (auto k : j.second) {
            temp[k.second] = max(temp[k.second], dp[k.first] + 1);
        }
        for (auto k : j.second) {
            dp[k.second] = max(temp[k.second], dp[k.second]);
        }
    }

    int res = 0;
    for (int i = 0;i < n;++i) {
        res = max(res, dp[i]);
    }
    cout << res + 1 << endl;
}


int main() {

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}