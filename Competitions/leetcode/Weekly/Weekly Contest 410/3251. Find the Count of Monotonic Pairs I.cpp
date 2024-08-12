#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[2001][1001];
    int mod = 1e9 + 7;

    int rec(int i, int prev1, vector<int> &v) {
        if (i==v.size())
            return 1;

        int &ans = dp[i][prev1];

        if (ans != -1)
            return ans;

        int prev2 = i ? v[i-1]-prev1 : 1e9; 

        ans = 0;
        for (int x=max(prev1, v[i]-prev2) ; x<=v[i] ; x++) {
            ans += rec(i+1, x, v)%mod;
            ans %= mod;
        }

        // for (int x=prev1 ; x<=v[i] ; x++) {
        //     int rest = v[i]-x;
        //     if (rest > prev2) continue;

        //     ans += rec(i+1, x, v)%mod;
        //     ans %= mod;
        // }

        return ans;
    }

    int countOfPairs(vector<int>& v) {
        memset(dp, -1, sizeof dp);
        return rec(0, 0, v);
    }
};