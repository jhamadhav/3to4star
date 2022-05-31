#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector<pair<int, int>> cord = { {-1,0},{1,0},{0,-1},{0,1} };
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && y >= 0 && x < m&& y < n);
}

void solve() {
    int n, m;
    cin >> n >> m;

    string arr[n];
    for (int i = 0;i < n;++i) {
        cin >> arr[i];
    }

    vector<int> res;
    int count = 0;
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j) {
            // do bfs only when land is there i.e. 1
            if (arr[i][j] == '0') continue;

            // pair is for {i,j}
            queue<pair<int, int>> q;
            q.push({ j,i });
            arr[i][j] = '0';

            while (q.empty() == false) {
                int len = q.size();
                while (len--) {
                    pair<int, int> temp = q.front();
                    q.pop();

                    int x = temp.first;
                    int y = temp.second;

                    count++;

                    for (int k = 0;k < 4;++k) {
                        int cx = x + cord[k].first;
                        int cy = y + cord[k].second;

                        if (isValid(cx, cy, n, m) && arr[cy][cx] == '1') {
                            arr[cy][cx] = '0';
                            q.push({ cx,cy });
                        }
                    }
                }
            }

            // for(string s : arr){
            //     cout<<s<<endl;
            // }cout<<endl;

            res.push_back(count);
            count = 0;
        }
    }

    sort(res.rbegin(), res.rend());

    int ans = 0;
    for (int i = 1;i < res.size();i += 2) {
        ans += res[i];
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}