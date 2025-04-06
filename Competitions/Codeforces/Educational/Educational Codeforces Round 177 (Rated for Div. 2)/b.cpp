#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        ll n,k,x;
        cin>>n>>k>>x;

        vector<ll> a(n);
        for (int i=0 ; i<n ; i++) {
            cin>>a[i];

            if (i)
                a[i] += a[i-1];
        }

        ll ans = 0;
        ll sm = a[n-1];

        for (int i=0 ; i<n ; i++) {
            ll target = x;
            if (i)
                target += a[i-1];

            int r = lower_bound(a.begin(), a.end(), target) - a.begin(); 

            if (r == n) {
                // not enough
                ll y = a[n-1];
                if (i)
                    y -= a[i-1];

                ll s = 0;
                ll e = k-1;

                while(s<e) {
                    ll mid = (s+e+1)/2;

                    if ((y + mid * sm) < x) {
                        s = mid;
                    } else {
                        e = mid-1;
                    }
                }

                ll needed = s;
                if (needed == k-1) continue;

                ans += k-1-needed;
            } else {
                ans += k; 
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}