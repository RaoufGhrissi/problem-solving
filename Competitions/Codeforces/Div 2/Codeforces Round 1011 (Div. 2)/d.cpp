#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e17
#define mod 998244353
using namespace std;

ll x,y;

ll dp[60][60][60];

ll rec(int xx, int yy, int k) {
    if (!k) {
        if (!xx && !yy) {
            return 0;
        }

        return inf;
    }

    if (dp[xx][yy][k] != -1)
        return dp[xx][yy][k];

    dp[xx][yy][k] = rec(xx, yy, k-1);

    if (xx-k >= 0) {
        dp[xx][yy][k] = min(dp[xx][yy][k], (1ll<<k) + rec(xx-k, yy, k-1));
    }

    if (yy-k >= 0)
        dp[xx][yy][k] = min(dp[xx][yy][k], (1ll<<k) + rec(xx, yy-k, k-1));

    return dp[xx][yy][k];
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    memset(dp, -1, sizeof dp);
    
    while(t--) {
        cin>>x>>y;

        ll res = inf;
        for (int i=0 ; i<60 ; i++) {
            
            for (int j=0 ; j<60 ; j++) {
                if ((x>>i) == (y>>j)) {
                    res = min(res, rec(i, j, 59));
                }
            }
        }

        cout<<res<<endl;
    }
}

int main() {
    solve();
    return 0;
}