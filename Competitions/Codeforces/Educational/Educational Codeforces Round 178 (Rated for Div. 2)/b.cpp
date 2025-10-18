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
        int n;
        cin>>n;

        vector<ll> v(n), mx(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            mx[i] = v[i];
            if (i)
                mx[i] = max(mx[i], mx[i-1]);
        }

        ll sm = 0;
        ll cum = 0;
        for (int j=n-1 ; j>-1 ; j--) {
            ll res = cum + mx[j];
            cum += v[j];
            cout<<res<<" ";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}