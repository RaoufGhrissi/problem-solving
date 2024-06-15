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
        ll n, m, k;
        cin>>n>>m>>k;

        map<ll, ll> rows;

        vector<vector<ll>> points;
        vector<bool> extream(k, 0);

        for (int i=0 ; i<k ; i++) {
            ll x, y;
            cin>>x>>y;

            points.push_back({x ,y, i});
            rows[x] = !rows.count(x) ? y : min(rows[x], y);
        }

        ll ans = 0;

        sort(points.begin(), points.end());
        ll mx = 1e10;

        for (int i=k-1 ; i>-1 ; i--) {
            ll x = points[i][0];
            ll y = points[i][1];
            ll index = points[i][2];

            if (y < mx && y == rows[x]) {
                mx = y;
                extream[index] = 1;
            }
        }

        ll prev = 0;
        for (int i=0 ; i<k ; i++) {
            ll x = points[i][0];
            ll y = points[i][1];
            ll index = points[i][2];
            if (extream[index]) {
                ans += (x-prev) * (y-1);
                prev = x;
            }

            if (i==k-1) {
                if (x < n) {
                    ans += (n-prev) * m;
                }
            }
        }

        cout<<ans<<endl;
        for (int i=0 ; i<k ; i++) {
            cout<<extream[i]<<" ";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}