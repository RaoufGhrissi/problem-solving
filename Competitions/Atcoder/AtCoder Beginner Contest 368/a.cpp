#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t = 1;
    //cin>>t;

    while(t--) {
        ll n, k; 
        cin>>n>>k;

        ll v[n];

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        for (int i=n-k ; i<n ; i++)
            cout<<v[i]<<" ";

        for (int i=0 ; i<n-k ; i++)
            cout<<v[i]<<" ";
    }
}

int main() {
    solve();
    return 0;
}