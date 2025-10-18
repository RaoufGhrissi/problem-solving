#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    vector<ll> resultArray(vector<int>& v, int k) {
        vector<ll> ans(k, 0);

        int n = v.size();
        ll dp[n][k];

        memset(dp, 0, sizeof dp);

        dp[0][v[0]%k] = 1;
        for (int i=1 ; i<n ; i++) {
            int rest = v[i]%k;
            dp[i][rest] = 1;

            for (int d=0 ; d<k ; d++) {
                int r = (d*rest)%k;
                dp[i][r] += dp[i-1][d];
            }
        }

        for (int i=0 ; i<n ; i++) {
            for (int d=0 ; d<k ; d++) {
                ans[d] += dp[i][d];
            }
        }


        return ans;
    }
};