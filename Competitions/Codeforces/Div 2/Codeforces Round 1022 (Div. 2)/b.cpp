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
        int n,x;
        cin>>n>>x;

        if (n == 1) {
            if (x) cout<<x;
            else cout<<-1;

            cout<<endl;
            continue;
        }
        ll ans = 0;
        ll ones = 0;

        for (int i=0 ; i<32 ; i++) {
            ll mask = 1<<i;

            if (mask&x) { // 1
                ans += mask;
                ones++;
            }
        }

        int diff = n - ones;

        if (diff <= 0) {
            cout<<ans<<endl;
            continue;
        }

        if (diff&1) diff++;

        for (int i=0 ; i<32 ; i++) {
            if (diff <= 0) break;
            ll mask = 1<<i;

            int zeros = n;
            if (mask&x) zeros--;

            int change = zeros/2 * 2;
            ans += mask*min(change, diff);
            diff -= change;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}