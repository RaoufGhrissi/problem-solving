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

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int a, b;
        cin>>a>>b;

        int mx = max(a, b);
        int mi = min(a, b);

        if (mx == mi) {
            cout<<0<<endl;
        } else if (mx%mi == 0) {
            cout<<1<<endl;
        } else {
            cout<<2<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}