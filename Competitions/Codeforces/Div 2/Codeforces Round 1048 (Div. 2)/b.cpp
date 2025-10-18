#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, ll>

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
        int n, m;
        cin>>n>>m;

        vector<ll> a(n);
        vector<pp> b(n);
        for (int i=0 ; i<n ; i++)
            cin>>a[i];

        for (int i=0 ; i<n ; i++)
            b[i] = {a[i] * m, i};

        sort(b.begin(), b.end());

        ll seconds = min(n, m);
        ll ans = 0;
        ll it = 0;

        for (int i=n-1 ; i>-1 ; i--) {
            if (it == seconds) break;
            ans += b[i].first - it*a[b[i].second];
            it++;
        }
        
        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}