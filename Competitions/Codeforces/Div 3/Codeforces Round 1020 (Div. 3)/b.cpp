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
        int n, x;
        cin>>n>>x;

        for (int i=0 ; i<x ; i++)
            cout<<i<<" ";

        for (int i=x+1 ; i<n ; i++)
            cout<<i<<" ";

        if (x<n)
            cout<<x<<endl;
        else
            cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}