#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
using namespace std;


void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

const int N = 2*1e5 + 1;
ll occ[N];
ll cum[N];

ll x, n, previous, cnt, sm, used;
ll y;

void solve() {
    FAST;

#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        cin>>n>>y;

        for (int i=0 ; i<N ; i++) {
            occ[i] = 0;
        }

        for (int i=0 ; i<n ; i++) {
            cin>>x;
            occ[x]++;
        }

        for (int i=0 ; i<N ; i++) {
            cum[i] = occ[i];
            
            if (i)
                cum[i] += cum[i-1];
        }
        
        ll ans = -1e18;
        for (int multiplier=2 ; multiplier<N ; multiplier++) {
            sm = 0;
            used = 0;

            for (int num=1 ; num<N ; num++) {
                previous = (num - 1) * multiplier;
                if (previous >= N) break;

                x = min(num * multiplier, N-1);
                cnt = cum[x] - cum[previous];
                sm += cnt * num;
                used += min(occ[num], cnt);
            }

            ll res = sm - ((n - used) * 1ll * y);
            ans = max(ans, res);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}