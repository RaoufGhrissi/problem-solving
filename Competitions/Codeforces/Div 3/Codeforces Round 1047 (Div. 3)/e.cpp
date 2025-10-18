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
    cin>>t;

    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<int> a(n);

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
        }
        
        map<vector<int>, int> cycle;
        map<int, vector<int>> index;
        int it = 0;

        while(it<k && !cycle.count(a)) {
            cycle[a] = it;
            index[it] = a;

            map<int, int> occ;
            for (int i=0 ; i<n ; i++) {
                occ[a[i]]++;
            }
            
            set<int> mex;
            for (int i=0 ; i<=n ; i++)
                mex.insert(i);

            for (int i=0 ; i<n ; i++) {
                if (mex.count(a[i])) {
                    mex.erase(a[i]);
                }
            }

            for (int i=0 ; i<n ; i++) {
                if (occ[a[i]] == 1) {
                    a[i] = min(a[i], *mex.begin());
                } else {
                    a[i] = *mex.begin();
                }
            }

            it++;
        }

        if (it == k) {
            ll ans = 0;

            for (int i=0 ; i<n ; i++) {
                ans += a[i];
            }
            cout<<ans<<endl;
        } else {
            ll ans = 0;
            int start = cycle[a];
            int end = it;

            int id = (k-start) % l + start;

            for (int i=0 ; i<n ; i++) {
                ans += index[id][i];
            }
            cout<<ans<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}