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
        int x, y, z;
        cin>>x>>y>>z;

        int a = x|z;
        int b = x|y;
        int c = y|z;

        if (((a&b) == x) && ((b&c) == y) && ((a&c) == z)) yes();
        else no();
    }
}

int main() {
    solve();
    return 0;
}