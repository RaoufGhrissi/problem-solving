#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll,ll>
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

        vector<int> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }

        vector<pp> t = {{v[0], 1}};

        for (int i=1 ; i<n ; i++) {
            int z = t.size();
            if (v[i] == v[i-1]) {
                t[z-1].second++;
            } else {
                t.push_back({v[i], 1});
            }
        }

        ll ans = 1e15;
        for (int i=0 ; i<t.size() ; i++) {
            ans = min(ans, (n-t[i].second)*t[i].first);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}