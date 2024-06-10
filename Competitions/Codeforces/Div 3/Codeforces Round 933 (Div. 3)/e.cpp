#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define inf 1e18

using namespace std;

int const N = 2*1e5;
ll dp[N];

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, k, d;
        cin>>n>>m>>k>>d;
        vector<ll> cost(n);

        vector<vector<int>> v(n, vector<int>(m));
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                cin>>v[i][j];
            }

            // dp[i] = min cost to have a bridge until position i
            dp[0] = 1;
            multiset<ll> st;
            st.insert(dp[0]);
            int l = 0;
            for (int j=1 ; j<m ; j++) {
                int f = j-d-1;
                if (l<f)
                    st.erase(st.lower_bound(dp[l++]));

                dp[j] = 1+v[i][j] + *st.begin();
                st.insert(dp[j]);
            }

            cost[i] = dp[m-1];
        }

        ll ans = inf;
        for (int i=0 ; i<n ; i++) {
            if (i)
                cost[i] += cost[i-1];

            int f = i-k+1;
            if (f<0) continue;

            ll cnt = cost[i];
            if (f)
                cnt -= cost[f-1];

            ans = min(ans, cnt);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}