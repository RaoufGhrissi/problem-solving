#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

void decomp(ll x, ll &k, vector<ll> &ans) {
    ll mm = x;

    for (ll i=2 ; i*i<=x ; i++) {
        while(mm%i == 0) {
            mm /= i;
            ans.push_back(i);
        }
    }

    if (mm > 1) {
        ans.push_back(mm);
    }
}

pp dp[1<<20];

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    vector<ll> ans;
    while(t--) {
        ll x, y, k;
        cin>>x>>y>>k;

        ll g = gcd(x, y);

        x /= g;
        y /= g;

        // first
        ans.clear();
        decomp(x, k, ans);

        int n = ans.size();
        if (*max_element(ans.begin(), ans.end()) > k) {
            cout<<-1<<endl;
            continue;
        }
        
        dp[0] = {1, 1};
        for (int i=1 ; i<(1<<n) ; i++)
            dp[i] = {21, 1};

        for (int i=0 ; i<(1<<n) ; i++) {
            for (int j=0 ; j<n ; j++) {
                int mask = 1<<j;

                if (mask & i) {
                    auto [g, c] = dp[mask^i];

                    if (c * ans[j] <= k) {
                        dp[i] = min(dp[i], {g, c * ans[j]});
                    } else {
                        dp[i] = min(dp[i], {g+1, ans[j]});
                    }
                }
            }
        }

        ll cnt = 0;

        if (!ans.empty()) {
            cnt = dp[(1<<n)-1].first;
        }
        
        // second 
        ans.clear();
        decomp(y, k, ans);

        if (*max_element(ans.begin(), ans.end()) > k) {
            cout<<-1<<endl;
            continue;
        }   

        n = ans.size();
        dp[0] = {1, 1};
        for (int i=1 ; i<(1<<n) ; i++)
            dp[i] = {21, 1};

        for (int i=0 ; i<(1<<n) ; i++) {
            for (int j=0 ; j<n ; j++) {
                int mask = 1<<j;

                if (mask & i) {
                    auto [g, c] = dp[mask^i];

                    if (c * ans[j] <= k) {
                        dp[i] = min(dp[i], {g, c * ans[j]});
                    } else {
                        dp[i] = min(dp[i], {g+1, ans[j]});
                    }
                }
            }
        }

        if (!ans.empty()) {
            cnt += dp[(1<<n)-1].first;
        }
        
        cout<<cnt<<endl;
    }
}

int main() {
    solve();
    return 0;
}