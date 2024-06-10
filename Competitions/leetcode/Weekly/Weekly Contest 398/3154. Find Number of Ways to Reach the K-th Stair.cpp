#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    unordered_map<int, int> dp[30][2];
    int rec(int i, int j, int isLastDec, int &k) {
        if (i>(k+1)) return 0;

        if (dp[j][isLastDec].count(i)) return dp[j][isLastDec][i];

        int &ans = dp[j][isLastDec][i];
        ans = i==k ? 1: 0;

        ans += rec(i+(1<<j), j+1, 0, k);
        if (!isLastDec && i>0)
            ans += rec(i-1, j, 1, k);

        return ans;
    }

    int waysToReachStair(int k) {
        return rec(1, 0, 0, k);
    }
};