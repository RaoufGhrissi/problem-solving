#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

#define ll long long

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int mod = 1e9 + 7;

    bool safe(int i, int j, int &n, int &m) {   
        return i>-1 && j>-1 && i<n && j<m;
    }

    int countPaths(vector<vector<int>>& v) {
        ll ans = 0;

        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> all;
        vector<vector<ll>> dp(n, vector<ll>(m, 0));

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                all.push_back({v[i][j], i, j});
            }
        }

        sort(all.begin(), all.end());
        int sz = all.size();

        int i = 0;

        while(i<sz) {
            int val = all[i][0];
            int row = all[i][1];
            int col = all[i][2];

            dp[row][col] = 1;

            for (int d=0 ; d<4 ; d++) {
                int di = row + dx[d];
                int dj = col + dy[d];

                if (safe(di, dj, n, m) && v[di][dj] < v[row][col]) {
                    dp[row][col] = (dp[row][col] + dp[di][dj])%mod;
                }
            }

            i++;
            ans = (ans + dp[row][col])%mod;
        }

        return ans;
    }
};