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
        int n;
        cin>>n;

        vector<ll> v(n);

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        vector<int> cnt(30, 0);
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<30 ; j++) {
                ll mask = 1ll<<j;

                if (mask&v[i])
                    cnt[j]++;
            }
        }

        ll ans = 0;

        for (int i=0 ; i<n ; i++) {
            ll tot = 0;

            for (int j=0 ; j<30 ; j++) {
                ll mask = 1ll<<j;

                ll bit = mask&v[i];

                // 1 -> needs 0
                if (bit > 0) {
                    ll bits = n-cnt[j];
                    tot += (1ll<<j)*bits;
                } else { 
                // 0 -> needs 1
                    ll bits = cnt[j];
                    tot += (1ll<<j)*bits;
                }
            }

            ans = max(ans, tot);
        }


        cout<<ans<<endl;


        

        
    }
}

int main() {
    solve();
    return 0;
}