#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)

// initialize max
int mx = 5e4; // i.e. 5 x 10^4

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> vec(mx + 3); // graph for different days

    unordered_map<int, int> tp; // count of stamps that chef has, initially: all = 0
    for (int i = 0;i < n;i++) {
        int x;
        cin >> x;
        tp[x]++;
    }

    // (day stamp1 stamp2) in vec
    for (int i = 0;i < m;i++) {
        int d, a, b;
        cin >> d >> a >> b;
        vec[d].push_back({ a,b });
    }

    int max_type[mx + 3]; // maximum type into which a stamp of type t can exchanged into 
    for (int i = 0;i <= mx;i++) {
        max_type[i] = i;
    }

    for (int i = mx;i >= 0;i--) { // reverse chronological order 
        unordered_map<int, vector<int>> graph;

        // for a particular day 
        for (auto& x : vec[i]) {
            graph[x.first].push_back(x.second);
            graph[x.second].push_back(x.first);
        }

        vector<vector<int>> comp; // to store the component array for every subgraph associated to time T

        // extract nodes from graph
        map<int, int> vis; // visited
        int C = 0;
        for (auto it = graph.begin(); it != graph.end(); it++) {

            if (vis.find(it->first) == vis.end()) {
                vis[it->first] = C;
                queue<int> q;
                vector<int> v;

                q.push(it->first);
                while (!q.empty()) {
                    int node = q.front();
                    v.push_back(node);
                    q.pop();

                    for (auto jt = graph[node].begin(); jt != graph[node].end(); jt++) {
                        if (vis.find(*jt) == vis.end()) {
                            q.push(*jt);
                            vis[*jt] = C;
                        }
                    }
                }
                C++;
                comp.push_back(v); // one sub-graph consisting of connected components inserted 
            }
        }

        for (int j = 0;j < (int)comp.size();j++) {
            int val = -1;
            for (auto& x : comp[j]) {
                val = max(val, max_type[x]);
            }
            for (auto& x : comp[j]) { // assign this maxval for every component of this subgraph
                max_type[x] = val;
            }
        }
    }

    ll res = 0;
    for (int i = 0;i <= mx;i++) {
        res += (ll)max_type[i] * 1LL * tp[i];
    }
    cout << res << endl;
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