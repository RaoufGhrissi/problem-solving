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

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        bool zeros = 0;
        bool ok = 1;
        for (int i=0 ; i<n ; i++) {
            if (!v[i]) zeros = 1;
            if (i && !v[i] && !v[i-1]) {
                ok = 0;
                break;
            }
        }

        if (!ok || !zeros)
            yes();
        else
            no();
    }
}

int main() {
    solve();
    return 0;
}