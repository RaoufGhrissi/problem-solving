#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;

    int dp[1000][1000];

    int rec(int i, int j, int &t, vector<int> &dx, vector<int> &dy, vector<vector<int>>& v) {
        int &ans = dp[i][j];

        if (ans != -1)
            return ans;

        ans = v[i][j];
        for (int d=0 ; d<3 ; d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (!(x>-1 && x<n && y>-1 && y<n)) continue;

            if (t == 1 && y<=x) continue;
            if (t == 2 && y>=x) continue;
            
            ans = max(ans, v[i][j] + rec(x, y, t, dx, dy, v));
        }

        return ans;
    }

    int maxCollectedFruits(vector<vector<int>>& v) {
        int ans = 0;
        memset(dp, -1, sizeof dp);
        n = v.size();

        for (int i=0 ; i<n ; i++)
            ans += v[i][i];
        
        vector<int> dx = {1, 1, 1}, dy = {-1, 0, 1};
        int t = 1;
        ans += rec(0, n-1, t, dx, dy, v);

        memset(dp, -1, sizeof dp);
        t = 2;
        ans += rec(n-1, 0, t, dy, dx, v);
        return ans;
    }
};