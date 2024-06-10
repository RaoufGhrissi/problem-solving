#include <bits/stdc++.h>
#define loop(n) for (int i=0 ; i<n ; i++)
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))
#define sortDesc(v) sort(all(v), greater<int>())
#define ll long long
#define mod int(1e9 + 7)

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<ll> v(n);
        loop(n) cin>>v[i];
        ll ans = 0;
        vector<ll> dp(n);
        dp[0] = max(v[0], 0ll);
        ll mx = 0;
        ll sm = 0;

        loop(n) {
            if (i)
                dp[i] = max(v[i], dp[i-1]+v[i]);
            mx = max(mx, dp[i]);
            sm += v[i];
        }

        while(k--) {
            sm += mx%mod;
            sm %= mod;
            mx += mx;
            mx %= mod;
        }
        
        if (sm < 0) sm += mod;
        cout<<sm<<endl;
    }
}

int main() {
    solve();
    return 0;
}