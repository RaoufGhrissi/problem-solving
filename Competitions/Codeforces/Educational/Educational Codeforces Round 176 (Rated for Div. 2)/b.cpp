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
        int n,k;
        cin>>n>>k;

        vector<ll> v(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        ll ans = 0;
        if (k==1) {
            for (int i=0 ; i<n ; i++) {
                ll res = v[i];
                
                if (i)
                    res = max(res, v[i] + v[0]);

                if (i<n-1)
                    res = max(res, v[i] + v[n-1]);

                ans = max(ans, res);
            }
        } else {
            sort(v.begin(), v.end());
            int i = n-1;
            k++;
            while(k-- && i>-1) {
                ans += v[i--];
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}