#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, ll>
#define inf 1e18

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<ll> v(n);

        for (int i=0 ; i<n ; i++) cin>>v[i];

        ll sm = 0;
        ll mx = 0;

        int ans = 0;

        for (int i=0 ; i<n ; i++) {
            sm += v[i];
            mx = max(mx, v[i]);

            ll rest = sm - mx;
            if (rest == mx)
                ans++;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}