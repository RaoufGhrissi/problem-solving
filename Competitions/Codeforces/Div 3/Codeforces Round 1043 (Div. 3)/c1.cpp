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
        ll n;
        cin>>n;

        ll ans = 0;
        ll d = pow(3, 18);

        for (int i=18 ; i>-1 ; i--) {
            ll q = n / d;

            ans += q*(d*3 + i*(d/3));
            n -= d*q;

            d /= 3;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}