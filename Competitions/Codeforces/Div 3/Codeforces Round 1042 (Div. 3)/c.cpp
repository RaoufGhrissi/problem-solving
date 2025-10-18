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

pp convert(int x, int k) {
    int a = x%k;
    int b = k - a;

    return {min(a, b), max(a, b)};
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, k;
        cin>>n>>k;

        multiset<pp> v1;

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;

            v1.insert(convert(x, k));
        }

        bool ok = 1;

        for (int i=0 ; i<n ; i++) {
            int y;
            cin>>y;
            
            pp p = convert(y, k);
            if (v1.count(p)) {
                v1.erase(v1.lower_bound(p));
            } else {
                ok = 0;
            }
        }

        if (ok) yes();
        else no();
        
    }
}

int main() {
    solve();
    return 0;
}