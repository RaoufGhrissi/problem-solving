#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
using namespace std;

int m = 998244353;
map<vector<int>, ll> dp;
int rec(int c1, int c2, int c3, int c4, int no9ba) {
    if (!c1 && !c2 && !c3 && !c4)
        return 1;

    vector<int> v = {c1, c2, c3, c4, no9ba};
    if (dp.count(v) && dp[v] != -1)
        return dp[v];

    ll &ans = dp[v];
    ans = 0;

    if (no9ba) {
        if (c1) {
            ans += c1*rec(c1-1, c2, c3, c4, 0)%m;
            ans %= m;
        }

        if (c4) {
            ans += c4*rec(c1, c2, c3, c4-1, 1)%m;
            ans %= m;
        }
    } else {
        if (c2) {
            ans += c2*rec(c1, c2-1, c3, c4, 0)%m;
            ans %= m;
        }

        if (c3) {
            ans += c3*rec(c1, c2, c3-1, c4, 1)%m;
            ans %= m;
        }
    }

    return ans;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int c1, c2, c3, c4;
        cin>>c1>>c2>>c3>>c4;
        int x = 2;

        ll res = rec(c1, c2, c3, c4, 0);

        cout<<res + rec(c1, c2, c3, c4, 1)<<endl;
    }
}

int main() {
    solve();
    return 0;
}