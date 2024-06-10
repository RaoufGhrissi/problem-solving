#include <bits/stdc++.h>

using namespace std;

#define inf 1e9
#define ll long long

class Solution {
public:
    int dp[1000][11];
    int occ[1000][10];

    int f(int i, int prev, vector<vector<int>>& v, int &n, int &m) {
        if (i==m) return 0;

        int &ans = dp[i][prev];

        if (ans != -1)
            return ans;

        ans = 1e9;

        for (int c=0 ; c<10 ; c++) {
            if (prev != 10 && prev==c) continue; // skip the same number as prev
            int cost = n - occ[i][c]; // o(1) instead o(n*m)
            ans = min(ans, cost + f(i+1, c, v, n, m));
        }

        return ans;
    }

    int minimumOperations(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        // preprocessing
        for (int col=0 ; col<m ; col++) {
            for (int line=0 ; line<n ; line++) {
                occ[col][v[line][col]]++;
            }
        }

        memset(dp, -1, sizeof dp);
        return f(0, 10, v, n, m);
    }
};