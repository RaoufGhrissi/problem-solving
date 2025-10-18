#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t = 1;
    //cin>>t;

    string sq;
    while(t--) {
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        vector<int> ids[k];

        for (int i=0 ; i<n ; i++) {
            ids[s[i]-'a'].push_back(i);
        }

        int next[n];
        int dp[n];

        for (int i=0 ; i<n ; i++) {
            next[i] = 0;
            for (int j=0 ; j<k ; j++) {
                int pos = lower_bound(ids[j].begin(), ids[j].end(), i+1) - ids[j].begin();

                if (pos == ids[j].size()) {
                    next[i] = n;
                    break;
                }

                next[i] = max(next[i], ids[j][pos]);
            }
        }

        for (int i=n-1 ; i>-1 ; i--) {
            if (next[i] == n)
                dp[i] = 1;
            else
                dp[i] = dp[next[i]] + 1;
        }
            
        int q;
        cin>>q;

        while(q--) {
            cin>>sq;

            int m = sq.size();
            int id = -1;
            bool ples = 1; 
            
            for (int i=0 ; i<m ; i++) {
                int o = sq[i] - 'a';
                int pos = lower_bound(ids[o].begin(), ids[o].end(), id+1) - ids[o].begin();

                if (pos == ids[o].size()) {
                    ples = 0;
                    break;
                }

                id = ids[o][pos];
            }

            if (!ples) {
                cout<<0<<endl;
                continue;
            }

            cout<<dp[id]<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}