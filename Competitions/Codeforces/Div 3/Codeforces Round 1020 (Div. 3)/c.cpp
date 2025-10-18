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
        int n, k;
        cin>>n>>k;

        vector<int> a(n), b(n);
        int mi = 1e9;
        int mx = 0;

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
            mi = min(mi, a[i]);
            mx = max(mx, a[i]);
        }

        int x = -1;
        bool ok = 1;
        for (int i=0 ; i<n ; i++) {
            cin>>b[i];
        }

        for (int i=0 ; i<n ; i++) {
            if (b[i]==-1) {
                continue;
            }

            if (x==-1) {
                x = a[i] + b[i];
            } else {
                int x1 = a[i]+b[i];
                if (x1 != x) {
                    ok = 0;
                    break;
                }
            }
        }

        if (!ok) {
            cout<<0<<endl;
            continue;
        }

        if (x != -1) {
            for (int i=0 ; i<n ; i++) {
                if (b[i] == -1) {
                    int rest = x-a[i];
                    if (rest >=0 && rest<=k) {
                        continue;
                    }

                    ok = 0;
                    break;
                } 
            }

            if (ok) {
                cout<<1;
            } else {
                cout<<0;
            }

            cout<<endl;
        } else {
            cout<<k-(mx-mi)+1<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}