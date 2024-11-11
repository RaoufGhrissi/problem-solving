#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution {
public:
    int m = 1e9 + 7;

    ll dp[2001][2000];
    ll cum[2001][2000];

    int possibleStringCount(string s, int k) {
        vector<int> v;

        ll all = 1;
        ll occ = 0;
        int n = s.size();

        for (int i=0; i<n ; i++) {
            if (i && s[i] != s[i-1]) {
                v.push_back(occ);
                all = (all * occ)%m;
                occ = 1;
            } else {
                occ++;
            }
        }

        v.push_back(occ);
        all = (all * occ)%m;

        int sz = v.size();
        if (sz >= k) return all;

        for (int i=sz ; i>=0 ; i--) {
            n_dp = 
            for (int j=0 ; j<k ; j++) {
                if (i==sz) dp[i][j] = 1;
                else if (!j) dp[i][j] = 0;
                else {
                    int r = j-1;
                    int l = j-min(j, v[i]);

                    dp[i][j] = cum[i+1][r];

                    if (l)
                        dp[i][j] -= cum[i+1][l-1];

                    if (dp[i][j] < 0)
                        dp[i][j] += m;

                    dp[i][j] %= m;
                }

                cum[i][j] = dp[i][j];
                if (j)
                    cum[i][j] += cum[i][j-1];
            }
        }

        return (all - dp[0][k-1] + m)%m; 
    }
};