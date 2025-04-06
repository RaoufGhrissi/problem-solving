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
        ll x,y;
        cin>>x>>y;

        ll xx = x;
        ll yy = y;

        ll k = 0;
        for (int i=0 ; i<60 ; i++) {
            ll mask = 1ll<<i;

            ll xk = mask&x;
            ll yk = mask&y;

            if (xk && yk) {
                k |= mask;
                x += mask;
                y += mask; 
            }
        }

        if (((xx+yy+2*k) == (xx+k)^(yy+k))) {
            cout<<k<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}