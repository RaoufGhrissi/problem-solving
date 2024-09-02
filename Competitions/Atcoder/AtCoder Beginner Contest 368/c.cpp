#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

bool can(ll sz, ll x, ll h) {
    ll three = (sz+h)/3 - (h-1)/3;
    ll ones = sz+1 - three;

    return ones + 3*three >= x;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t = 1;
    //cin>>t;

    while(t--) {
        ll n; 
        cin>>n;

        ll h=0;

        for (int i=0 ; i<n ; i++) {
            h++;
            ll x;
            cin>>x;

            ll s = 0;
            ll e = 1e18;

            while(s<e) {
                ll mid = (s+e)/2;

                if (can(mid, x, h)) {
                    e = mid;
                } else {
                    s = mid+1;
                }
            }

            h += s;
        }

        cout<<h<<endl;
    }
}

int main() {
    solve();
    return 0;
}