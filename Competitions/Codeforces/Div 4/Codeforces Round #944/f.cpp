#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        ll r;
        cin>>r;

        ll ans = 0;
        ll x = -r;
        ll x2 = x*x;
        ll r2 = r*r;
        ll rplus2 = (r+1)*(r+1);

        while(x<=r) {
            ll i = 0, j = r;
            // search inf j

            while(i<j) {
                ll mid = (i+j)/2;
                ll y2 = mid*mid;
                ll comp = x2+y2;
                if (comp < r2)
                    i = mid+1;
                else
                    j = mid;
            }

            ll s = i;
            // search max j 
            i = 0;
            j = r;

            while(i<j) {
                ll mid = (i+j+1)/2;
                ll y2 = mid*mid;
                ll comp = x2+y2;
                if (comp < rplus2)
                    i = mid;
                else
                    j = mid-1;
            }

            ll e = i;

            ll res = 2*(e-s+1);

            if (!s) res--;

            ans += res;

            x++;
            x2 = x*x;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}