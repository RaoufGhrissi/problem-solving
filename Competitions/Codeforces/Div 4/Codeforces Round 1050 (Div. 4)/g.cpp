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

const int N = 2*1e5 + 1;
int occ[N];
vector<int> divs[N];

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    for (int i=2 ; i<N ; i++) {
        for (int j=i ; j<N ; j+=i) {
            divs[j].push_back(i);
        }
    }

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n), mx_vals;

        for (int i=0 ; i<n ; i++) 
            cin>>v[i];

        for (int i=0 ; i<N ; i++) {
            occ[i] = 0;
        }
        
        int mx = 0;
        for (int i=0 ; i<n ; i++) {
            int num = v[i];
            int tot = i+1;

            for (int &d:divs[num]) {
                occ[d]++;
                if (occ[d] < tot) {
                    mx = max(mx, occ[d]);
                } else if (occ[d] == 1) {
                    mx_vals.push_back(d);
                }
            }

            for (int i=0 ; i<mx_vals.size() ; i++) {
                if (mx_vals[i] == -1) continue;

                if (occ[mx_vals[i]] < tot) {
                    mx = max(mx, occ[mx_vals[i]]);
                    mx_vals[i] = -1;
                }
            }

            cout<<mx<<" ";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}