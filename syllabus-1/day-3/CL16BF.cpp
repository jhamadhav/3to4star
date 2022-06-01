#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000007

void topoSort(vector<int>& res, vector<vector<int>>& arr, stack<int>& ls, vector<int>& indegree) {
    while (ls.empty() == false) {
        int node = ls.top();
        ls.pop();

        res.push_back(node);

        for (int i : arr[node]) {
            indegree[i]--;
            if (indegree[i] == 0)    ls.push(i);
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    int p, q;
    cin >> p >> q;
    p--;q--; // to make nodes start index 0

    // edges
    vector<vector<int>> arr(n);
    vector<int> indegree(n, 0);
    for (int i = 0;i < m;++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a].push_back(b);
        indegree[b]++;
    }

    // list of all nodes with 0 indegree
    stack<int> ls;
    for (int i = 0; i < n;++i) {
        if (indegree[i] == 0) {
            ls.push(i);
        }
    }

    //kahn algo for toposort
    vector<int> topo;
    topoSort(topo, arr, ls, indegree);

    // //print topo list
    // for(int i: topo){
    //     cout<<i<<" ";
    // }cout<<endl;

    //we will go in reverse for top list and calulate dp 
    vector<int> dp(n, 0);
    dp[q] = 1;
    for (int i = n - 1; i >= 0; --i) {
        int curr = topo[i];
        for (int node : arr[curr]) {
            dp[curr] += dp[node];
            dp[curr] %= MOD;
        }
    }
    cout << dp[p] << endl;
}

int main() {

    int t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }

    return 0;
}