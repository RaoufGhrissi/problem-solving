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

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    t = 1;
    //cin>>t;

    while(t--) {
        int n, x;
        cin>>n>>x;

        vector<int> w(n);

        for (int i=0; i<n; i++) {
            cin>>w[i];
        }

        vector<pp> dp(1<<n, {21, 0});
        dp[0] = {1, 0};

        for (int i=0 ; i<(1<<n) ; i++) {
            for (int j=0 ; j<n ; j++) {
                int mask = 1<<j;

                if (mask & i) {
                    auto [g, c] = dp[mask^i];

                    if (c + w[j] <= x) {
                        dp[i] = min(dp[i], {g, c + w[j]});
                    } else {
                        dp[i] = min(dp[i], {g+1, w[j]});
                    }
                }
            }
        }

        cout<<dp[(1<<n)-1].first;
    }
}

int main() {
    solve();
    return 0;
}