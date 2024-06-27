#include <bits/stdc++.h>
#define inf (int)1e9;
using namespace std;

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1000][1001];
        int mod = 1e9 + 7;

        for (int i=0 ; i<n ; i++) {
            for (int kk=0 ; kk<=k ; kk++) {
                if (!i)
                    dp[i][kk] = !kk;
                else {
                    dp[i][kk] = dp[i-1][kk];
                    int l = kk - min(i, kk);
                    if (l) {
                        dp[i][kk] -= dp[i-1][l-1];
                        if (dp[i][kk] < 0)
                            dp[i][kk] += mod;
                    }
                }

                if (kk > 0)
                    dp[i][kk] += dp[i][kk-1];

                dp[i][kk] %= mod;
            }
        }

        return !k ? dp[n-1][k] : (dp[n-1][k] + mod - dp[n-1][k-1])%mod;
    }
};