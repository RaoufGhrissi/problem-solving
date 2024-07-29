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
        ll n, x;
        cin>>n>>x;

        ll ans = 0;

        for (ll a=1 ; a<n ; a++) {
            ll c = 1;
            bool stop = 0;
            while(a*c <= n) {
                ll b = min(x-(a+c), (n-a*c)/(a+c));
                if (b > 0)
                    ans += b;
                else
                    break;
                c++;
            }

            if (stop)
                break;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}