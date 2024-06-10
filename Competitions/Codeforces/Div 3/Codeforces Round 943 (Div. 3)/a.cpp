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
        int x;
        cin>>x;

        int mx = 1;
        for (int i=1 ; i<x ; i++) {
            if (__gcd(i, x) + i > __gcd(mx, x) + mx) {
                mx = i;
            }
        }

        cout<<mx<<endl;
    }
}

int main() {
    solve();
    return 0;
}