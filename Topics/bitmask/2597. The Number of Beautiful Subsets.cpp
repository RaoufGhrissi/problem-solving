#include <bits/stdc++.h>
//https://leetcode.com/problems/the-number-of-beautiful-subsets/
using namespace std;

class Solution {
public:
    int dp[20][1<<20];
    int solve(int i, int mask, vector<int>& v, map<int, vector<int>> &mp, int &k) {
        if (i == v.size())
            return mask ? 1 : 0;

        if (dp[i][mask] != -1)
            return dp[i][mask];

        dp[i][mask] = solve(i+1, mask, v, mp, k);

        int target = v[i]-k;
        if (mp.count(target)) {
            for (auto &index:mp[target]) {
                if (mask&(1<<index))
                    return dp[i][mask];
            }
        }

        dp[i][mask] += solve(i+1, mask|(1<<i), v, mp, k);
        return dp[i][mask]; 
    }

    int beautifulSubsets(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        map<int, vector<int>> mp;
        int n = v.size();
        memset(dp, -1, sizeof dp);

        for (int i=0 ; i<n ; i++) {
            mp[v[i]].push_back(i);
        }

        return solve(0, 0, v, mp, k);
    }
};