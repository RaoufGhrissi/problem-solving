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
        int n, m;
        cin>>n>>m;

        vector<int> v(m);
        for (int i=0 ; i<m ; i++)
            cin>>v[i];

        bool inc = 1;
        for (int i=1 ; i<m ; i++) {
            if ((v[i] - v[i-1]) != 1) {
                inc = 0;
                break;
            }
        }

        if (inc) {
            cout<<n-v[m-1]+1<<endl;
            continue;
        }

        int prev = -1;
        bool ok = 1;
        int mx = v[0];
        for (int i=1 ; i<m ; i++) {
            if (v[i] > v[i-1]) { // diff = 1
                if (v[i]-v[i-1] != 1) {
                    ok = 0;
                    break;
                }
                mx = v[i];
            } else {
                if (v[i] != 1) {
                    ok = 0;
                    break;
                }
                if (prev != -1 && mx != (prev+1)) {
                    ok = 0;
                    break;
                }

                prev = mx;
            }
        }

        if (ok) {
            cout<<1<<endl;
        } else {
            cout<<0<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}