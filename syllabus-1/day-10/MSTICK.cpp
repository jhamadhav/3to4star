#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int MAXNUM = 1e5 + 10;
vector<ll> stMax(4 * MAXNUM, INT_MIN), stMin(4 * MAXNUM, INT_MAX), arr(MAXNUM);

ll build(int l, int r, int index, vector<ll>& st, int t = 0) {

    if (l == r) {
        // cout<<l<<"-"<<r<<": "<<arr[l]<<endl;
        st[index] = arr[l];
        return arr[l];
    }

    int mid = l + (r - l) / 2;
    ll res = 0;
    ll left = build(l, mid, 2 * index + 1, st, t);
    ll right = build(mid + 1, r, 2 * index + 2, st, t);
    if (t == 1) {
        res = min(left, right);
    }
    else {
        res = max(left, right);
    }

    // cout<<l<<"-"<<r<<": "<<res<<endl;
    st[index] = res;
    return res;
}

ll query(int l, int r, int index, int a, int b, vector<ll>& st, int t = 0) {
    if (l >= a && r <= b) {
        return st[index];
    }
    if (r < a || l > b) {
        if (t == 1) return INT_MAX;
        return INT_MIN;
    }

    int mid = l + (r - l) / 2;
    ll left = query(l, mid, 2 * index + 1, a, b, st, t);
    ll right = query(mid + 1, r, 2 * index + 2, a, b, st, t);

    if (t == 1) {
        return min(left, right);
    }
    return max(left, right);
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0;i < n;++i) {
        cin >> arr[i];
    }
    build(0, n - 1, 0, stMax);
    build(0, n - 1, 0, stMin, 1);

    // for(int i=0;i<4*n;++i){
    //     cout<<stMax[i]<<" ";
    // }cout<<endl;

    // for(int i=0;i<4*n;++i){
    //     cout<<stMin[i]<<" ";
    // }cout<<endl;


    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        int m = query(0, n - 1, 0, l, r, stMin, 1);
        int M = query(0, n - 1, 0, l, r, stMax);
        int Mp = max(query(0, n - 1, 0, 0, l - 1, stMax), query(0, n - 1, 0, r + 1, n - 1, stMax));

        // cout<<"m: "<<m<<" M: "<<M<<" Mp: "<<Mp<<endl;

        double res = m, temp = (M - m) / 2.0;
        res += (temp > Mp) ? temp : Mp;

        printf("%.1lf\n", res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}