#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[2000][2000];
    
    int rec(int i, int j, int &tot, vector<int> &v) {
        if (i>=j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int &ans = dp[i][j];
        ans = 0;
        if (v[i]+v[i+1] == tot) {
            ans = max(ans, 1 + rec(i+2, j, tot, v));
        }
        
        if (v[i]+v[j] == tot) {
            ans = max(ans, 1 + rec(i+1, j-1, tot, v));
        }
        
        if (v[j-1]+v[j] == tot) {
            ans = max(ans, 1 + rec(i, j-2, tot, v));
        }
        
        return ans;
    }

    int maxOperations(vector<int>& v) {
        int n = v.size();
        
        vector<int> sm = {v[0]+v[1], v[0]+v[n-1], v[n-2]+v[n-1]};
        int ans = 0;
        
        for (auto &a:sm) { // 3 = const
            memset(dp, -1, sizeof dp);
            ans = max(ans, rec(0, n-1, a, v));
        }
        
        return ans;
    }
};