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

        if (n%2 == 0) {
            cout<<-1<<endl;
        } else {
            for (int i=1 ; i<=n ; i++) {
                if (i&1) cout<<i<<" ";
            }

            for (int i=1 ; i<=n ; i++) {
                if (!(i&1)) cout<<i<<" ";
            }

            cout<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}