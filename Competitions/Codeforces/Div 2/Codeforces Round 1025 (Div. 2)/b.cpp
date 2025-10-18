#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

ll cnt(int n, int m) {
    int ln = log2(n);
    if ((1<<ln) < n)
        ln++;

    int lm = log2(m);
    if ((1<<lm) < m)
        lm++;

    return ln + lm;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, m, a, b;
        cin>>n>>m>>a>>b;

        ll ans = 1e9;
        // h top
        if (a > 1) {
            ans = min(ans, 1 + cnt(n-a+1, m));
        }

        // h down
        if (a < n) {
            ans = min(ans, 1 + cnt(a, m));
        }

        // v left
        if (b > 1) {
            ans = min(ans, 1 + cnt(n, m-b+1));
        } 

        // v right
        if (b < m) {
            ans = min(ans, 1 + cnt(n, b));
        }

        if (ans == 1e9) {
            cout<<0;
        } else {
            cout<<ans;
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}