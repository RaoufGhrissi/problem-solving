#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

int mat[100][100];
int dp[100][100];

bool dfs(int i, int j, int &n, int &m) {
    if (i == n-1 && j == m-1) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 0;

    if (i+1 < n && mat[i+1][j])
        dp[i][j] |= dfs(i+1, j, n, m);

    if (j+1 < m && mat[i][j+1])
        dp[i][j] |= dfs(i, j+1, n, m);

    return dp[i][j];
}

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m;

        cin>>n>>m;

        map<int, vector<pp>> pos;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                int x;
                cin>>x;

                pos[x].push_back({i, j});
                for (int d=2 ; d<=sqrt(x) ; d++) {
                    if (x%d == 0) {
                        pos[d].push_back({i, j});
                        pos[x/d].push_back({i, j});
                    }
                }
            }
        }

        int ans = 1;
        for (auto &a:pos) {
            memset(mat, 0, sizeof mat);
            memset(dp, -1, sizeof dp);
            for (auto &p:a.second) {
                mat[p.first][p.second] = 1;
            }

            if (!mat[0][0]) continue;
            if (dfs(0, 0, n, m)) ans = max(ans, a.first);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}