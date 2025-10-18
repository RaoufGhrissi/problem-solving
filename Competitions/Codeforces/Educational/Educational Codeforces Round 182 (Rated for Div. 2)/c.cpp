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

ll dp[100][2];
int n;

int mod = 998244353;

ll rec(int i, int swaped, vector<int> &a, vector<int> &b) {
    if (i==n) {
        return 1;
    }

    ll &ans = dp[i][swaped];

    if (ans != -1)
        return ans;

    ans = 0;
    int mxA = swaped ? b[i-1] : a[i-1];
    int mxB = swaped ? a[i-1] : b[i-1];

    if ((a[i] >= mxA) && (b[i] >= mxB)) {
        ans = (ans + rec(i+1, 0, a, b)) % mod;
    }

    if ((b[i] >= mxA) && (a[i] >= mxB)) {
        ans = (ans + rec(i+1, 1, a, b)) % mod; 
    }

    return ans;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        cin>>n;

        int mx = 0;
        
        vector<int> a(n), b(n), tot(n);
        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
            tot[i] = a[i];

            mx = max(mx, a[i]);
        }

        for (int i=0 ; i<n ; i++) {
            cin>>b[i];
            tot[i] += b[i];
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<=1 ; j++) {
                dp[i][j] = -1;
            }
        }

        ll ans = rec(1, 0, a, b);
        ans = (ans + rec(1, 1, a, b)) % mod;

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}