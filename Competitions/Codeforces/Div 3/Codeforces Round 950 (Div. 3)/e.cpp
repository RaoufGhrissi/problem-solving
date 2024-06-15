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
        ll x, y, z, k;

        cin>>x>>y>>z>>k;

        ll ans = 0;

        for (int i=1 ; i<=x ; i++) {
            for (int j=1 ; j<=y ; j++) {
                if ((i*j > k) || ((k%(i*j)) > 0)) continue;

                ll zz = k/(i*j);

                if (zz > z) continue;

                ans = max(ans, (x-i+1)*(y-j+1)*(z-zz+1));
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}