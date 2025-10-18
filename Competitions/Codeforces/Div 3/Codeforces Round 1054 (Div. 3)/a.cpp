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

        vector<int> v(n);
        int ops = 0;

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        int p = 1;
        for (int i=0 ; i<n ; i++) {
            if (v[i] == 0) {
                v[i] = 1;
                ops++;
            }

            p *= v[i];
        }

        if (p > 0) {
            cout<<ops<<endl;
        } else {
            cout<<ops+2<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}