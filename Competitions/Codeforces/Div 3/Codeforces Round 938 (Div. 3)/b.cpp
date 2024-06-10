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
        int n, c, d;
        cin>>n>>c>>d;

        map<int,int> occ;
        int mi = 1e9;

        for (int i=0 ; i<n*n ; i++) {
            int x;
            cin>>x;

            occ[x]++;
            mi = min(mi, x);
        }

        int mat[n][n];
        mat[0][0] = mi;

        bool ok = 1;

        for (int i=0 ; i<n ; i++) {
            if (!ok) break;
            for (int j=0 ; j<n ; j++) {
                if (!i && !j) continue;

                int val1 = -1, val2 = -1;
                if (i) val1 = mat[i-1][j] + c;
                if (j) val2 = mat[i][j-1] + d;

                if (val1 != -1 && val2 != -1 && val1 != val2) {
                    ok = 0;
                    break;
                }

                mat[i][j] = max(val1, val2);

                if (!occ.count(mat[i][j])) {
                    ok = 0;
                    break;
                }

                occ[mat[i][j]]--;
                if (!occ[mat[i][j]]) occ.erase(mat[i][j]);
            }
        }

        if (ok) cout<<"YES";
        else cout<<"NO";

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}