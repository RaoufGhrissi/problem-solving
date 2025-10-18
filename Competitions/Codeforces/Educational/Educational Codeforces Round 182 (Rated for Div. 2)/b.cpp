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

        int z = 0;
        int id = -1;

        vector<int> p(n);
        for (int i=0 ; i<n ; i++) {
            cin>>p[i];
            if (p[i] == 0) {
                z++;
                id = i;
            }
        }

        if (z == 1) {
            set<int> st(p.begin(), p.end());

            for (int i=1 ; i<=n ; i++) {
                if (!st.count(i)) {
                    p[id] = i;
                    break;
                }
            }
        }

        int l = 0;
        int r = n-1;

        while(l<n && (p[l] == (l+1)))
            l++;

        while(r>-1 && (p[r] == (r+1)))
            r--;

        if (l>=r) {
            cout<<0<<endl;
        } else {
            cout<<r-l+1<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}