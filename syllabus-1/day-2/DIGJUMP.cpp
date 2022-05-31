#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
    string s;
    cin >> s;

    // wrap repeating numbers i.e. 99999 -> 99 
    string temp = "";
    for (int i = 0; i < s.length();) {
        temp += s[i];

        if (i + 1 < s.length() && s[i] == s[i + 1]) {
            while (i + 1 < s.length() && s[i] == s[i + 1]) ++i;
        }
        else {
            ++i;
        }
    }
    s = temp;

    int n = s.length();

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    // add each occurrence index of a number to an array
    vector<vector<int>> m(10);
    for (int i = 0;i < n;++i) {
        int num = s[i] - '0';
        m[num].push_back(i);
    }

    //visited array
    vector<int> visited(n, 0);

    int count = 0;
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (q.empty() == false) {
        int len = q.size();
        while (len--) {
            int node = q.front();
            q.pop();

            if (node == n - 1) {
                cout << count << endl;
                return;
            }

            if (node - 1 >= 0 && visited[node - 1] == 0) {
                q.push(node - 1);
                visited[node - 1] = 1;
            }

            if (node + 1 < n && visited[node + 1] == 0) {
                q.push(node + 1);
                visited[node + 1] = 1;
            }

            for (auto i : m[s[node] - '0']) {
                if (visited[i] == 0) {
                    q.push(i);
                    visited[i] = 1;
                }
            }

        }

        count++;
    }
    cout << count << endl;
}

int main() {
    solve();
    return 0;
}