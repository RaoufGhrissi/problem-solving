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
        int n, x;
        cin>>n>>x;

        vector<int> v(n);
        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }

        sort(v.begin(), v.end(), greater<int>());

        int ans = 0;
        int mi = 0;
        int cnt = 0;
        for (int i=0 ; i<n ; i++) {
            if (v[i] >= x) {
                ans++;
            } else {
                mi = v[i];
                cnt++;
                if (mi*cnt >= x) {
                    ans++;
                    mi = 0;
                    cnt = 0;
                }
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}