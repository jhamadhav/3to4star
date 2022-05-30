#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    int n, e;
    cin >> n >> e;

    vector<int> bucketArr(n + 1, 1);
    vector<int> edgeCount(n + 1, 0);

    int u = -1, v = -1;
    for (int i = 0;i < e;++i) {
        int a, b;
        cin >> a >> b;

        if (u == v) {
            u = a;
            v = b;
        }

        edgeCount[a]++;
        edgeCount[b]++;
    }

    // if edge count is even
    if (e % 2 == 0) {
        cout << 1 << endl;
        for (int i = 1;i <= n;++i) {
            cout << bucketArr[i] << " ";
        }cout << endl;
        return;
    }

    // if edge count is odd
    // if a node with odd edge count exists
    int node = -1;
    for (int i = 1;i <= n;++i) {
        if (edgeCount[i] % 2 == 1) {
            node = i;
            bucketArr[i] = 2;
            break;
        }
    }

    if (node != -1) {
        cout << 2 << endl;
        for (int i = 1;i <= n;++i) {
            cout << bucketArr[i] << " ";
        }cout << endl;
        return;
    }

    // else we select 1 edge and it's connected one
    for (int i = 1;i <= n;++i) {
        if (i == u) {
            bucketArr[i] = 2;
        }
        else if (i == v) {
            bucketArr[i] = 3;
        }
    }

    cout << 3 << endl;
    for (int i = 1;i <= n;++i) {
        cout << bucketArr[i] << " ";
    }cout << endl;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}