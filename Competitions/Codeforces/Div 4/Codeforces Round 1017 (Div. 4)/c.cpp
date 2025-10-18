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
        vector<int> ans(2*n + 1, -1);
        vector<bool> p(2*n+1);

        for (int i=1 ; i<= n ;i++) {
            for (int j=1 ; j<=n ; j++) {
                int x;
                cin>>x;

                ans[i+j] = x;
                p[x] = 1;
            }
        }

        for (int i=1 ; i<=2*n ; i++) {
            if(p[i] == 0) {
                cout<<i<<" ";
                break;
            }
        }

        for (int i=1 ; i<=2*n ; i++) {
            if (ans[i] == -1) continue;
            cout<<ans[i]<<" ";
        }

        cout<<endl; 
    }
}

int main() {
    solve();
    return 0;
}