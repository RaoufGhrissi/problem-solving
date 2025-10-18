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

        map<int,int> occ;

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;
            occ[x]++;
        }

        bool ok = 0;
        bool started = 0;
        int prev = -1;
        for (auto &a:occ) {
            if (a.second >= 4) {
                ok = 1;
                break;
            }

            if (a.second >= 2) {
                if (a.first == prev + 1 && started) {
                    ok = 1;
                    break;
                } else {
                    started = 1;
                }
            } else {
                if (a.first != prev+1) {
                    started = 0;
                }
            }

            prev = a.first;
        }

        if (ok) {
            yes();
        } else {
            no();
        }

    
        

    }
}

int main() {
    solve();
    return 0;
}