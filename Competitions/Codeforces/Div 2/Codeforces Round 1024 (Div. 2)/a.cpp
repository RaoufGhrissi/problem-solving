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
        int n,m,p,q;
        cin>>n>>m>>p>>q;

        int ps = n/p;
        int rest = n%p;

        if (rest) {
            yes();
        } else {
            int tot = q*ps;
            
            if (tot == m) {
                yes();
            } else {
                no();
            }
        }

    }
}

int main() {
    solve();
    return 0;
}