#include <bits/stdc++.h>
#define  ll long long
#define pp pair<int,int>
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

        int m = 2*n;

        vector<ll> a(m);
        vector<ll> odd(m, 0);
        vector<ll> even(m, 0); 

        for (int i=0 ; i<m ; i++) {
            cin>>a[i];
            if (i&1) odd[i] = a[i];
            else even[i] = a[i];
        }

        for (int i=1 ; i<m ; i++) {
            a[i] += a[i-1];
            odd[i] += odd[i-1];
            even[i] += even[i-1];
        }

        for (int i=1 ; i<=n ; i++) {
            ll ans = 0;
            int l = i-2;
            int start = i-1;
            int end = m-i;

            if (i>1) {
                ans -= a[l];
                ans += a[m-1];
                if (end > -1)
                    ans -= a[end];
            }

            if (start&1){ 
                ans += even[end] - odd[end];
                if (l > -1)
                    ans += odd[l] - even[l]; 
            } else {
                ans -= even[end] - odd[end];
                if (l > -1)
                    ans -= odd[l] - even[l]; 
            }

            cout<<ans<<" ";
        }

        cout<<endl;

    }
}

int main() {
    solve();
    return 0;
}