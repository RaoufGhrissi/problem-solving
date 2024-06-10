#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, q;
        cin>>n>>q;

        vector<int> v(n);
        map<int,vector<int>> pos;

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            if (i)
                v[i] ^= v[i-1];

            pos[v[i]].push_back(i);
        }

        while(q--) {
            int l, r;
            cin>>l>>r;
            l--;
            r--;

            // k = 2
            bool k2 = 0;
            if (l) {
                if (v[r] == v[l-1]) k2 = 1;
            } else {
                if (!v[r]) k2 = 1;
            }

            if (k2) {
                cout<<"YES"<<endl;
                continue;
            }

            // k = 3
            int vx = v[r];
            int p1 = lower_bound(pos[vx].begin(), pos[vx].end(), l) - pos[vx].begin();
            
            int sz = pos[vx].size();
            if (p1 < sz && pos[vx][p1] < r) {
                int vy = l ? v[l-1] : 0;
                int p = lower_bound(pos[vy].begin(), pos[vy].end(), pos[vx][p1]+1) - pos[vy].begin();

                int sz = pos[vy].size();
                if (p < sz && pos[vy][p] < r)
                    k2 = 1;
            }

            if (k2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}