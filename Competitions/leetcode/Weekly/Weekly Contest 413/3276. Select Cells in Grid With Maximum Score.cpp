#include <bits/stdc++.h>

using namespace std;


#define ll long long

class Solution {
public:
    int dp[101][1025];
    int n;
    
    int rec(int mx, int rowsMask, vector<vector<int>>& v) {
        if (rowsMask == (1<<n)-1)
            return 0;
        
        if (mx == 0)
            return 0;
        
        int &ans = dp[mx][rowsMask];
        
        if (ans != -1)
            return ans;
        
        ans = rec(mx-1, rowsMask, v);
        for (int i=0 ; i<n ; i++) {
            int mask = 1<<i;
            if (mask&rowsMask) continue;
            if (!v[i][mx]) continue;
            
            ans = max(ans, mx + rec(mx-1, rowsMask | mask, v));
        }
        
        return ans;
    }
    
    int maxScore(vector<vector<int>>& t) {
        memset(dp, -1, sizeof dp);
        
        n = t.size();
        int m = t[0].size();
        
        vector<vector<int>> v(n, vector<int>(101, 0));
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                v[i][t[i][j]] = 1;
            }
        }
        
        return rec(100, 0, v);
    }
};

int main() {
    vector<vector<int>> v = {{1,2,3},{4,3,2},{1,1,1}};
    cout<<Solution().maxScore(v);
}