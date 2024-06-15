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
        int mx = 0;
        int id = 0;

        vector<string> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];

            int res = 0;
            for (auto &c:v[i])
                res += c == '#';

            if (res > mx) {
                id = i;
                mx = res;
            }
        }

        int s = 1e9;
        int e = 0;

        for (int i=0 ; i<m ; i++) {
            if (v[id][i] == '.') continue;
            s = min(s, i);
            e = max(e, i);
        }

        cout<<id+1<<" "<<1+((s+e)/2)<<endl;

    }
}

int main() {
    solve();
    return 0;
}