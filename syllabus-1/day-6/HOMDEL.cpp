#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void apsp(vector<vector<int>>& paths) {
    int n = paths.size();
    for (int k = 0;k < n;++k) {
        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                paths[i][j] = min(paths[i][k] + paths[k][j], paths[i][j]);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < n;++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> paths = arr; // all pair shortest path ans 
    apsp(paths);

    int m;
    cin >> m;
    while (m--) {
        int s, g, d;
        cin >> s >> g >> d;

        int gtime = paths[s][g] + paths[g][d];
        cout << gtime << " " << abs(gtime - paths[s][d]) << endl;
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