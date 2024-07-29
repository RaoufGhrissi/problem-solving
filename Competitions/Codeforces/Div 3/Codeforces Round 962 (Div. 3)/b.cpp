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
        int n, k;
        cin>>n>>k;

        vector<string> v(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        int col = 0;
        int line = 0;

        while(line<n) {
            col = 0;
            while(col<n) {
                cout<<v[line][col];
                col += k;
            }
            cout<<endl;
            line += k;
        }
    }
}

int main() {
    solve();
    return 0;
}