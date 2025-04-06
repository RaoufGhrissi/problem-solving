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
ll cum[2000][2000][2];

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

        // 0 first come
        // 1 second come
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                dp[i][j][0] = 0;

                if (mat[i][j] != 'X'){
                    continue;
                }

                if (!i) {
                    dp[i][j][0] = 1;
                    continue;
                }

                int l = max(0, j-d+1);
                int r = min(m-1, j+d-1);

                ll sum = cum[i-1][r][0];
                if (l) {
                    sum -= cum[i-1][l-1][0];

                    if (sum < 0)
                        sum += mod;
                }

                dp[i][j][0] = (dp[i][j][0] + sum) % mod;

                sum = cum[i-1][r][1];
                if (l) {
                    sum -= cum[i-1][l-1][1];

                    if (sum < 0)
                        sum += mod;
                }

                dp[i][j][0] = (dp[i][j][0] + sum) % mod;
            }

            for (int j=0 ; j<m ; j++) {
                cum[i][j][0] = dp[i][j][0];
                if (j)
                    cum[i][j][0] = (cum[i][j][0] + cum[i][j-1][0]) % mod;
            }

            for (int j=0 ; j<m ; j++) {
                dp[i][j][1] = 0;
                if (mat[i][j] != 'X'){
                    continue;
                }

                int l = max(0, j-d);
                int r = min(m-1, j+d);
                
                ll sum = 0;
                if (l<j) {
                    sum = cum[i][j-1][0];
                    if (l)
                        sum -= cum[i][l-1][0];

                    if (sum < 0)
                        sum += mod;
                }

                dp[i][j][1] = (dp[i][j][1] + sum) % mod;
                
                sum = 0;

                if (j<r) {
                    sum = cum[i][r][0] - cum[i][j][0];
                    if (sum < 0)
                        sum += mod;
                }

                dp[i][j][1] = (dp[i][j][1] + sum) % mod;
            }

            for (int j=0 ; j<m ; j++) {
                cum[i][j][1] = dp[i][j][1];
                if (j)
                    cum[i][j][1] = (cum[i][j][1] + cum[i][j-1][1]) % mod;
            }
        }

        ll ans = 0;
        for (int col=0 ; col<m ; col++) {
            if (mat[n-1][col] == 'X') {
                ans = (ans + dp[n-1][col][1]) % mod;
                ans = (ans + dp[n-1][col][0]) % mod;
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}