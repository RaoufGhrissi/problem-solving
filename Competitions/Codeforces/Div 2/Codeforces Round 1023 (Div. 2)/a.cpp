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
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);

        int mx = -1;
        int mi = 1e9;
        for (int i=0 ; i<n ; i++) {
            cin>>v[i];

            mi = min(mi, v[i]);
            mx = max(mx, v[i]);
        }

        if (mi == mx) {
            no();
        } else {
            yes();

            for (int i=0 ; i<n ; i++) {
                if (v[i] == mx) {
                    cout<<1;
                } else {
                    cout<<2;
                }

                cout<<" ";
            }

            cout<<endl;
        }

    }
}

int main() {
    solve();
    return 0;
}