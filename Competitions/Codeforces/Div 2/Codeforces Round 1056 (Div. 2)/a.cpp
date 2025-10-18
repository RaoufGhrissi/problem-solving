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
        int n;
        cin>>n;

        int w = n;
        int l = 0;

        int ans = 1;
        while(w > 1 || l > 1) {
            ans += w/2 + l/2;
            l -= l/2;
            l += w/2;
            w -= w/2;
        }

        
        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}