#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
#define mod 998244353
using namespace std;

int n, m, d;

bool canMove(int i1, int j1, int i2, int j2) {
    return d*d >= ((i1-i2)*(i1-i2) + (j1-j2)*(j1-j2));
}

char mat[2000][2000];
ll dp[2000][2000][2];

ll rec(int i, int j, int cnt) {
    if (dp[i][j][cnt] != -1) {
        return dp[i][j][cnt];
    }

    dp[i][j][cnt] = 0;
 
    if (!i) {
        if (cnt == 0) {
            return 1;
        }
    }

    if (cnt == 1) { // came from down
        for (int col=0 ; col<m ; col++) {
            if (col != j && mat[i][col] == 'X' && canMove(i, j, i, col)) {
                dp[i][j][cnt] = (dp[i][j][cnt] + rec(i, col, 0)) % mod; //mod
            }
        }
    }

    if (i) {
        for (int col=0 ; col<m ; col++) {
            if (mat[i-1][col] == 'X' && canMove(i, j, i-1, col)) {
                dp[i][j][cnt] = (dp[i][j][cnt] + rec(i-1, col, 1)) % mod; //mod
            }
        }
    }

    return dp[i][j][cnt];
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        cin>>n>>m>>d;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                cin>>mat[i][j];
            }
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }

        ll ans = 0;
        for (int col=0 ; col<m ; col++) {
            if (mat[n-1][col] == 'X') {
                ans = (ans + rec(n-1, col, 1)) % mod;
                ans = (ans + rec(n-1, col, 0)) % mod;   
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}