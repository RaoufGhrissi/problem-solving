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
        int n, k;
        cin>>n>>k;

        map<int,int> occ;
        for (int i=0 ; i <n ; i++) {
            int x;
            cin>>x;
            occ[x]++;
        }

        bool valid = 0;
        for (auto &a:occ) {
            if (a.second >= k) valid = 1;
        }

        if (valid) cout<<k-1;
        else cout<<n;

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}