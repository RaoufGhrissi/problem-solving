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
        int n, m, x, y;
        cin>>n>>m>>x>>y;

        for (int i=0 ; i<n ; i++) {
            cin>>x;
        }

        for (int i=0 ; i<m ; i++) {
            cin>>x;
        }

        cout<<n+m<<endl;
    }
}

int main() {
    solve();
    return 0;
}