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
        int n;
        cin>>n;

        vector<int> p(n);
        for (int i=0 ; i<n ; i++) {
            cin>>p[i];
        }

        for (int i=0 ; i<n ; i++) {
            cout<<(n+1)-p[i]<<" ";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}