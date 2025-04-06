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
        int n;
        cin>>n;

        vector<int> p(n+1);
        vector<bool> vis(n+1);

        for (int i=1 ; i<=n ; i++)
            cin>>p[i];

        int ans = 0;
        for (int i=0 ; i<n ; i++) {
            int q;
            cin>>q;

            int cycleLength = 0;
            while(!vis[q]) {
                vis[q] = 1;
                cycleLength++;
                q = p[q];
            }

            ans += cycleLength;
            cout<<ans<<" ";
        }

        cout<<endl;
   }
}

int main() {
    solve();
    return 0;
}