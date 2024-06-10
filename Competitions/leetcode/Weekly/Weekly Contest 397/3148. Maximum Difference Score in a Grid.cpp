#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        int dp[n][m];
        int ans = -1e5;
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                dp[i][j] = -1e5;
                
                for (int col=0 ; col<j ; col++) {
                    dp[i][j] = max(dp[i][j], max(0, dp[i][col]) + v[i][j] - v[i][col]);
                }
                
                for (int line=0 ; line<i ; line++) {
                    dp[i][j] = max(dp[i][j], max(0, dp[line][j]) + v[i][j] - v[line][j]);
                }
                
                ans = max(dp[i][j], ans);
            }
        }

        return ans;
    }
};