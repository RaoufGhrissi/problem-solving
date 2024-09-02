#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll dp[500][500][2];
    int n, m, x, y;

    ll rec(int i, int prev, int k, vector<vector<vector<int>>>& v) {
        if (i==n)
            return k ? -1e18 : 0;

        if (!k)
            return 0;

        ll &ans = dp[i][prev][k];

        if (ans != -1)
            return ans;

        ans = rec(i+1, prev, k, v);

        if (i != x) {
            for (int j=0 ; j<3 ; j++) {
                if (v[i][j][1] == y) continue;
                if (k < 2 && v[i][j][1] == prev) continue;
                ans = max(ans, v[i][j][0] + rec(i+1, v[i][j][1], k-1, v));
            }
        }
        return ans;
    }

    long long maximumValueSum(vector<vector<int>>& t) {
        n = t.size();
        m = t[0].size();

        vector<vector<vector<int>>> v(n, vector<vector<int>>(m));

        x = 0;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                v[i][j] = {t[i][j], j};
            }
            sort(v[i].begin(), v[i].end(), greater<vector<int>>());
            if (v[i][0] > v[x][0])
                x = i;
        }

        ll ans = -1e18;
        for (int col=0 ; col<3 ; col++) {
            memset(dp, -1, sizeof dp);
            y = v[x][col][1];
            ans = max(ans, v[x][col][0] + rec(0, 0, 2, v));
        }

        return ans;
    }
};