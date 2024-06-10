#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<ll> v(n+1);
        map<int,int> pos;
        for (int i=1 ; i<=n ; i++) {
            cin>>v[i];
            pos[v[i]] = i;
        }

        int l = 1, r = n+1;

        while(r-l != 1) {
            int mid = (l+r)/2;

            if (v[mid] <= m)
                l = mid;
            else
                r = mid;
        }

        if (v[l] == m)
            cout<<0<<endl;
        else {
            cout<<1<<endl<<pos[m]<<" "<<pos[v[l]]<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}