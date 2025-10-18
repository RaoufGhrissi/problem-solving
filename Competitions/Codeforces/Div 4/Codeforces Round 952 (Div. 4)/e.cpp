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
        int n, m;
        cin>>n>>m;

        pp posa[n*m+1], posb[n*m+1];
        int a[n][m];
        int b[n][m];

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                cin>>a[i][j];
                posa[a[i][j]] = {i, j};
            }
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                cin>>b[i][j];
                posb[b[i][j]] = {i, j};
            }
        }

        bool ok = 1;

        int first = b[0][0];
        // swap first element

        pp p = posa[first];
        int x = p.first;
        int y = p.second;

        // swap line x1 and 0
        for (int col=0 ; col<m ; col++) {
            swap(posa[a[0][col]], posa[a[x][col]]);
            swap(a[0][col], a[x][col]);
        }

        // swap cols
        for (int col=0 ; col<m ; col++) {
            if (a[0][col] == b[0][col]) continue;

            int x = posa[b[0][col]].first;
            int y = posa[b[0][col]].second;

            if (x != 0) {
                ok = 0;
                break;
            }

            for (int line = 0 ; line<n ; line++) {
                swap(posa[a[line][col]], posa[a[line][y]]);
                swap(a[line][col], a[line][y]);
            }
        }

        for (int line=1 ; line<n ; line++) {
            if (a[line][0] == b[line][0]) continue;

            int x = posa[b[line][0]].first;
            int y = posa[b[line][0]].second;

            if (y != 0) {
                ok = 0;
                break;
            }

            for (int col=0 ; col<m ; col++) {
                swap(posa[a[line][col]], posa[a[x][col]]);
                swap(a[line][col], a[x][col]);
            }
        }

        // compare

        for (int i=0 ; i<n ; i++) {
            if (!ok)
                break;
            for (int j=0 ; j<m ; j++) {
                if (a[i][j] != b[i][j]) {
                    ok = 0;
                    break;
                }
            }
        }

        if (ok)
            cout<<"YES";
        else
            cout<<"NO";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}