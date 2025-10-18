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
        int k, n;
        cin>>n>>k;

        vector<int> v(n), occ(n+1), cnt(n+1);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            occ[v[i]]++;
        }

        bool ok = 1;
        for (int i=0 ; i<=n ; i++) {
            if (!occ[i]) continue;
            
            if (occ[i] % k) {
                ok = 0;
                break;
            }

            occ[i] /= k;
        }

        if (!ok) {
            cout<<0<<endl;
            continue;
        }

        int j = 0;
        ll ans = 0;
        for (int i=0 ; i<n ; i++) {
            while (j<n && (cnt[v[j]] < occ[v[j]])) {
                cnt[v[j]]++;
                j++;
            }

            ans += j-i;
            cnt[v[i]]--;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}