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
        ll a,b;
        cin>>a>>b;
        
        ll akberDiv = b&1 ? b : b/2;
        ll x = a*akberDiv + b/akberDiv;

        if (x&1) {
            x = -1;
        }

        cout<<x<<endl;
    }
}

int main() {
    solve();
    return 0;
}