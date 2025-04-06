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
        int n,k;
        cin>>n>>k;
        int op = 0;
        if (n&1) {
            op++;
            n = max(0, n - k);
            if (!n) {
                cout<<1<<endl;
                continue;
            }
        }

        int q = n/(k-1);
        int r = n%(k-1);

        if (r) q++;
        cout<<op + q<<endl;
    }
}

int main() {
    solve();
    return 0;
}