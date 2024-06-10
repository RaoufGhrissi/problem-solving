#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

int dp[200005][2][2];

bool rec(int i, int alice, int shouldTake, vector<ll> &v) {
    if (i==v.size() - 1) return alice;
    
    int &ans = dp[i][alice][shouldTake];
    if (ans != -1)
        return ans;

    ans = 0;
    if (shouldTake)
        return ans = rec(i+1, !alice, 0, v);

    int cnt = v[i];
    if (i) cnt -= v[i-1];
 
    if (cnt > 1) {
        if (alice)
            ans = rec(i+1, !alice, 0, v) || rec(i, !alice, 1, v);
        else
            ans = rec(i+1, !alice, 0, v) && rec(i, !alice, 1, v);
    } else {
        ans = rec(i+1, !alice, 0, v);
    }
    
    return ans;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        set<ll> s;

        for (int i=0 ; i<n ; i++) {
            ll x;
            cin>>x;
            s.insert(x);
        }

        vector<ll> v(s.begin(), s.end());

        memset(dp, -1, sizeof dp);
        
        bool res = rec(0, 1, 0, v);
        
        if (res) cout<<"Alice";
        else cout<<"Bob";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}