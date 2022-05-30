#include <bits/stdc++.h>
using namespace std;

#define endl "\n";

void solve() {
    int n, b;
    cin >> n >> b;

    if (b == 0 && n != 2) {
        cout << "YES" << endl;
        for (int i = 2;i <= n;++i) {
            cout << "1 " << i << endl;
        }
        return;
    }

    if (n == 2 && b == 1) {
        cout << "YES" << endl;
        cout << "1 2" << endl;
        return;
    }

    if (4 * b > n || (n == 2 && b == 0)) {
        cout << "NO" << endl;
        return;
    }

    int x = 2 * b + 2;
    cout << "YES" << endl;
    for (int i = 2;i <= x;++i) {
        cout << i - 1 << " " << i << endl;
    }

    for (int i = x + 1;i <= n;++i) {
        cout << x - 1 << " " << i << endl;
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}