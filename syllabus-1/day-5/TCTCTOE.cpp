#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

void solve() {
    vector<string> s(3);
    for (int i = 0;i < 3;++i) {
        cin >> s[i];
    }

    int cx = 0, co = 0, winx = 0, wino = 0;
    int x = 0, o = 0;
    //horizontal
    for (int i = 0;i < 3;++i) {
        for (int j = 0;j < 3;++j) {
            if (s[i][j] == 'X') {
                x++;
            }
            else if (s[i][j] == 'O') {
                o++;
            }
    }
        cx += x;
        co += o;
        if (x == 3) {
            winx++;
        }
        else if (o == 3) {
            wino++;
        }
}

    //vertical
    for (int i = 0;i < 3;++i) {
        x = 0, o = 0;
        for (int j = 0;j < 3;++j) {
            if (s[j][i] == 'X') {
                x++;
            }
            else if (s[j][i] == 'O') {
                o++;
            }
        }
        if (x == 3) {
            winx++;
        }
        else if (o == 3) {
            wino++;
        }
    }

    // left diagonal
    x = 0, o = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i][i] == 'X') {
            x++;
        }
        else if (s[i][i] == 'O') {
            o++;
        }
    }

    if (x == 3) {
        winx++;
    }
    else if (o == 3) {
        wino++;
    }

    // right diagonal
    x = 0, o = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i][2 - i] == 'X') {
            x++;
        }
        else if (s[i][2 - i] == 'O') {
            o++;
        }
    }

    if (x == 3) {
        winx++;
    }
    else if (o == 3) {
        wino++;
    }
    int ans = 2;
    if ((winx >= 1 && wino >= 1) || !(cx == co || cx == co + 1) || (wino >= 1 && cx == co + 1) || (winx >= 1 && cx == co)) {
        ans = 3;
    }
    else if ((winx >= 1 || wino >= 1) || (cx + co == 9)) {
        ans = 1;
    }
    cout << ans << endl;
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