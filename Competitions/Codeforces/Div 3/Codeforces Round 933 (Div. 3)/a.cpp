#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long

using namespace std;


void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, k;
        cin>>n>>m>>k;

        vector<ll> l(n), r(m);
        int ans = 0;

        for (int i=0 ; i<n ; i++) {
            cin>>l[i];
        }

        for (int i=0 ; i<m ; i++) {
            cin>>r[i];
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (l[i] + r[j] <= k)
                    ans++;
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}