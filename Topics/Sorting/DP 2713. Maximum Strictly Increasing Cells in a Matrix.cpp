#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>


class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& v) {
        int ans = 0;

        int n = v.size();
        int m = v[0].size();

        vector<int> mxRow(n, 0);
        vector<int> mxCol(m, 0);
        vector<vector<int>> all;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                all.push_back({v[i][j], i, j});
            }
        }

        sort(all.begin(), all.end());
        int sz = all.size();

        int i = 0;

        unordered_map<int,int> changed;

        while(i<sz) {
            int val = all[i][0];
            int row = all[i][1];
            int col = all[i][2];

            int j = i;
            dp[row][col] = 1 + max(mxRow[row], mxCol[col]);
            ans = max(ans, dp[row][col]);
            j++;
            
            while(j<sz && all[j][0] == all[j-1][0]) {
                row = all[j][1];
                col = all[j][2];

                dp[row][col] = 1 + max(mxRow[row], mxCol[col]);
                ans = max(ans, dp[row][col]);
                j++;        
            }

            // update
            row = all[i][1];
            col = all[i][2];

            mxRow[row] = max(mxRow[row], dp[row][col]);
            mxCol[col] = max(mxCol[col], dp[row][col]);
            i++;
            
            while(i<sz && all[i][0] == all[i-1][0]) {
                row = all[i][1];
                col = all[i][2];
                mxRow[row] = max(mxRow[row], dp[row][col]);
                mxCol[col] = max(mxCol[col], dp[row][col]);
                i++;        
            }
        
        }

        return ans;
    }
};



int main() {
    vector<vector<int>> v = {{0,-1},{-6,-6},{-1,8}}; // {{3, 1}, {3, 4}}; // 
    cout<<Solution().maxIncreasingCells(v);
}