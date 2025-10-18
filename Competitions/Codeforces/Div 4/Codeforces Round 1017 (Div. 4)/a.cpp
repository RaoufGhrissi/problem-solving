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
        string ans = "";
        string x;
        cin>>x;
        ans += x[0];
                cin>>x;
        ans += x[0];
                cin>>x;
        ans += x[0];

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}