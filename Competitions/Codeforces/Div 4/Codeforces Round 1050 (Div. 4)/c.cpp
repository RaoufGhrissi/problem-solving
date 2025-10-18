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
        int n, m;
        cin>>n>>m;

        ll ans = 0;
        int prev = 0;
        int side = 0;

        int a, b;

        for (int i=0 ; i<n ; i++) {
            cin>>a>>b;

            int r = a-2;
            int points = r-prev+1;

            if (points&1) side = !side;

            if (b != side) {
                side = !side;
                points++;
            }

            ans += points;
            prev = a;
        }

        if (prev < m)
            ans += m-prev;

        cout<<ans<<endl;
    }


}

int main() {
    solve();
    return 0;
}