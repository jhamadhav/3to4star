#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pairil pair<ll,int>

void djs(vector<vector<pair<int, int>>>& arr, int st, vector<ll>& costs) {
	vector<bool> visited(arr.size(), 0);

	priority_queue<pairil, vector<pairil>, greater<pairil>> q;
	q.push({ 0,st });
	costs[st] = 0;

	while (q.empty() == false) {
		pairil temp = q.top();
		q.pop();

		ll val = temp.first;
		int node = temp.second;

		if (visited[node] == 1) continue;

		// cout<<node + 1<<endl;

		visited[node] = 1;
		for (auto i : arr[node]) {
			if (visited[i.first] == 0) {
				if (costs[i.first] == -1) {
					costs[i.first] = i.second + val;
				}
				else {
					costs[i.first] = min(costs[i.first], (ll)i.second + val);
				}
				q.push({ costs[i.first],i.first });
			}
		}
	}
}
void solve() {
	int n, e;
	cin >> n >> e;

	int s, v, t;
	cin >> s >> v >> t;
	s--;    v--;    t--; // to make nodes 0 indexed

	vector<vector<pair<int, int>>> arr(n);
	for (int i = 0;i < e;++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;    b--; // to make nodes 0 indexed

		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}

	vector<ll> sCosts(n, -1), vCosts(n, -1), tCosts(n, -1);
	djs(arr, s, sCosts);
	djs(arr, v, vCosts);
	djs(arr, t, tCosts);

	ll res = -1;
	for (int i = 0;i < n;++i) {
		ll val = sCosts[i] + vCosts[i] + tCosts[i];
		if (res == -1 || res > val) {
			res = val;
		}
	}
	cout << res << endl;
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