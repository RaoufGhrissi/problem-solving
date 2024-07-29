#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, ll>
#define inf 1e18

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;

    ll mod = 1e9 + 7;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int n = s.size();

        vector<int> ones(n, 0), zeros(n, 0);
        map<int,ll> diff, cnt;

        diff[0] = 0;
        cnt[0] = 1;

        ll ans = 0;

        for (int i=0 ; i<n ; i++) {
            ones[i] = s[i]-'0';
            zeros[i] = '1'-s[i];

            if (i) {
                ones[i] += ones[i-1];
                zeros[i] += zeros[i-1];
            }
        }

        for (int i=0 ; i<n ; i++) {
            int d = zeros[i] - ones[i];
            ll r = n-1-i;

            if (!diff.count(d)) {
                diff[d] += i+1;
                cnt[d]++;
                continue;
            }
            
            ans += diff[d] + (cnt[d]*r)%mod + cnt[d] + (r*diff[d])%mod;
            ans %= mod;
            diff[d] += i+1;
            cnt[d]++;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}