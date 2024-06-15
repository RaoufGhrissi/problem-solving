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
        ll h, n;
        cin>>h>>n;

        vector<ll> a(n), c(n);

        for (int i=0 ; i<n ; i++)
            cin>>a[i];

        for (int i=0 ; i<n ; i++)
            cin>>c[i];

        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

        for (int i=0 ; i<n ; i++)
            pq.push({1ll, i*1ll});

        ll ans = 0;
        while(h>0) {
            vector<ll> t = pq.top();
            pq.pop();

            ll tour = t[0];
            ll i = t[1];

            h -= a[i];

            pq.push({tour+c[i], i});
            ans = tour;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}