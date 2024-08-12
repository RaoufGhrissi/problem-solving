#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const static int N = 2001, M = 1001;
    int dp[N][M];
    int cum[N][M];
    int mod = 1e9 + 7;

    int countOfPairs(vector<int>& v) {
        int n = v.size();
        int mod = 1e9 + 7;

        for (int prev1 = 0; prev1 < M; prev1++) {
            dp[n][prev1] = 1;
            cum[n][prev1] = dp[n][prev1];
            if (prev1)
                cum[n][prev1] += cum[n][prev1-1];
        }

        for (int i=n-1; i>-1; i--) {
            for (int prev1=0; prev1<M; prev1++) {
                dp[i][prev1] = 0;
                int prev2 = i ? v[i-1] - prev1 : 1e9;
                
                int l = max(prev1, v[i]-prev2);
                int r = v[i];

                if (l<=r) {
                    dp[i][prev1] = cum[i+1][r];
                    if (l)
                        dp[i][prev1] -= cum[i+1][l-1];

                    if (dp[i][prev1] < 0)
                        dp[i][prev1] += mod;
                }
                
                cum[i][prev1] = dp[i][prev1];
                if (prev1)
                    cum[i][prev1] += cum[i][prev1-1];

                cum[i][prev1] %= mod;
            }
        }

        return dp[0][0];
    }
};
