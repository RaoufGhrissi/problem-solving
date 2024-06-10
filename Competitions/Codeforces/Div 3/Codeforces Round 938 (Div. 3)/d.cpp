#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n, m, k;
        cin>>n>>m>>k;

        vector<int> a(n);

        for (int i=0 ; i<n ; i++) cin>>a[i];

        vector<int> b(m);
        for (int i=0 ; i<m ; i++) cin>>b[i];

        int ans = 0;

        map<int,int> bb;

        for (auto &e:b)
            bb[e]++;

        map<int,int> aa;

        int kk = 0;
        for (int i=0 ; i<m ; i++) {
            int x = a[i];
            if (!bb.count(x)) continue;

            if (aa[x] < bb[x]) {
                kk++;
            }

            aa[x]++;
        }

        ans += kk >= k;

        int i = 0;

        for (int j=m ; j<n ; j++) {
            int x = a[i];
            if (bb.count(x) && aa[x] <= bb[x]) {
                kk--;
            }

            aa[x]--;

            x = a[j];

            if (bb.count(x) && aa[x] < bb[x]) {
                kk++;
            }

            aa[x]++;

            if (kk >= k) ans++;
            i++;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}