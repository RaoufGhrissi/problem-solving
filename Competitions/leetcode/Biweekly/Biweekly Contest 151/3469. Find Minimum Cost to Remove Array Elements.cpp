#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[1000][1001];
    int n;
    
    int rec(int i, int prev, vector<int>& v) {
        if (i >= n)
            return v[prev];
        
        if (i == n-1)
            return prev == 1000 ? v[n-1] : max(v[prev], v[n-1]);
        
        int &ans = dp[i][prev];
        
        if (ans != -1)
            return ans;
        
        if (prev == 1000) {
            return ans = min({
                max(v[0], v[1]) + rec(3, 2, v),
                max(v[0], v[2]) + rec(3, 1, v),
                max(v[2], v[1]) + rec(3, 0, v),
            });
        } else {
            return ans = min({
                max(v[prev], v[i]) + rec(i+2, i+1, v),
                max(v[prev], v[i+1]) + rec(i+2, i, v),
                max(v[i], v[i+1]) + rec(i+2, prev, v),
            });
        }
    }
    
    int minCost(vector<int>& v) {
        memset(dp, -1, sizeof dp);
        n = v.size();
        
        if (n==1)
            return v[0];
        else if (n==2)
            return max(v[0], v[1]);
        
        return rec(0, 1000, v);
    }
};