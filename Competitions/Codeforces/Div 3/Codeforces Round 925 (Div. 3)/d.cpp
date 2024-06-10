#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        ll n, x, y;
        cin>>n>>x>>y;

        vector<ll> v(n);

        for (int i=0 ; i<n ; i++)
            cin>>v[i];
        
        map<pp, ll> occ;

        ll ans = 0;
        for (int i=0 ; i<n ; i++) {
            ll a = v[i];
            pp p = {(x-a%x)%x, a%y};
            ans += occ.count(p) ? occ[p] : 0;
            occ[{a%x, a%y}]++; 
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}