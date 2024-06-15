#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, ll>
#define inf 1e18

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<int> occ(7, m);

        string s;
        cin>>s;

        for (char &c:s)
            occ[c-'A']--;

        int ans = 0;

        for (int i=0 ; i<7 ; i++) {
            if (occ[i] > 0)
                ans += occ[i];
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}