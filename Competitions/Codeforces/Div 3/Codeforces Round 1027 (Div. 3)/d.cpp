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

        vector<pp> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i].first>>v[i].second;
        }

        if (n==1) {
            cout<<1<<endl;
            continue;
        }

        vector<ll> prefixMaxX(n), prefixMaxY(n), prefixMinY(n), prefixMinX(n);
        vector<ll> suffixMaxX(n), suffixMaxY(n), suffixMinY(n), suffixMinX(n);

        for (int i=0 ; i<n ; i++) {
            prefixMaxX[i] = v[i].first;
            prefixMinX[i] = v[i].first;

            prefixMaxY[i] = v[i].second;
            prefixMinY[i] = v[i].second;

            if (i) {
                prefixMaxX[i] = max(prefixMaxX[i], prefixMaxX[i-1]);
                prefixMinX[i] = min(prefixMinX[i], prefixMinX[i-1]);

                prefixMaxY[i] = max(prefixMaxY[i], prefixMaxY[i-1]);
                prefixMinY[i] = min(prefixMinY[i], prefixMinY[i-1]);
            }
        }

        for (int i=n-1 ; i>-1 ; i--) {
            suffixMaxX[i] = v[i].first;
            suffixMinX[i] = v[i].first;

            suffixMaxY[i] = v[i].second;
            suffixMinY[i] = v[i].second;

            if (i+1<n) {
                suffixMaxX[i] = max(suffixMaxX[i], suffixMaxX[i+1]);
                suffixMinX[i] = min(suffixMinX[i], suffixMinX[i+1]);

                suffixMaxY[i] = max(suffixMaxY[i], suffixMaxY[i+1]);
                suffixMinY[i] = min(suffixMinY[i], suffixMinY[i+1]);
            }
        }

        ll ans = inf;

        for (int i=0 ; i<n ; i++) {
            ll miX = inf;
            ll mxX = 0;
            ll miY = inf;
            ll mxY = 0;

            if (i) {
                miX = prefixMinX[i-1];
                mxX = prefixMaxX[i-1];
                mxY = prefixMaxY[i-1];
                miY = prefixMinY[i-1];
            }

            if (i+1<n) {
                miX = min(miX, suffixMinX[i+1]);
                mxX = max(mxX, suffixMaxX[i+1]);
                mxY = max(mxY, suffixMaxY[i+1]);
                miY = min(miY, suffixMinY[i+1]);
            }

            ll x = mxX-miX+1;
            ll y = mxY-miY+1;

            ll res = x*y;
            if (x*y == n-1) {
                res += min(x, y);
            }

            ans = min(ans, res);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}