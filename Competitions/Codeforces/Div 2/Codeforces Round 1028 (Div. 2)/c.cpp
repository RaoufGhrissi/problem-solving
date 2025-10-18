#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, pair<ll,ll>>
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

        vector<int> v(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];
    
        int g = v[0];
        for (int i=0 ; i<n ; i++)
            g = gcd(g, v[i]);

        int cnt = 0;
        for (int i=0 ; i<n ; i++) {
            if (v[i] == g) {
                cnt++;
            }
        }

        if (cnt > 0) {
            cout<<n-cnt<<endl;
            continue;
        }

        int miOps = 1e9;

        for (int j=0 ; j<n ; j++) {
            int ops = 0;
            int x = v[j];
            while(x > g) {
                int mi = 1e9;
                for (int i=0 ; i<n ; i++)
                    mi = min(mi, gcd(x, v[i]));

                x = mi;
                ops++;
            }

            miOps = min(miOps, ops);
        }

        cout<<miOps+n-1<<endl;
    }
}

int main() {
    solve();
    return 0;
}