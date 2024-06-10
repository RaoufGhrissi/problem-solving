#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

//https://codeforces.com/contest/1969/problem/C

ll dp[300000][11];

ll rec(int i, int k, vector<int> &v, int &n) {
    if (i >= n) return 0;

    if (dp[i][k] != -1)
        return dp[i][k];

    ll &ans = dp[i][k];
    
    int val = v[i];
    ans = val + rec(i+1, k, v, n);
    
    for (int j=i+1 ; j<n && (j-i) <= k ; j++) {
        val = min(val, v[j]);
        ans = min(ans, val*1ll*(j-i+1) + rec(j+1, k - (j-i), v, n));
    }

    return ans;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<int> v(n);
        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }

        memset(dp, -1, sizeof dp);
        cout<<rec(0, k, v, n)<<endl;
    }
}

int main() {
    solve();
    return 0;
}