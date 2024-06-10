#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int N = 5000;
    int dp[N][51];

    int maximumLength(vector<int>& v, int k) {
        if (!k) {
            map<int,int> occ;
            int mx = 0;
            for (auto &a:v) {
                occ[a]++;
                mx = max(mx, occ[a]);
            }

            return mx;
        }

        int ans = 0;
        int n = v.size();
        
        for (int i=0 ; i<n ; i++) {
            for (int kk=k ; kk>-1 ; kk--) {
                dp[i][kk] = 1;

                for (int j=0 ; j<i ; j++) {
                    if (v[i]==v[j])
                        dp[i][kk] = max(dp[i][kk], 1+dp[j][kk]);
                    else if (kk>0)
                        dp[i][kk] = max(dp[i][kk], 1+dp[j][kk-1]);
                }

                ans = max(ans, dp[i][kk]);
            }
        }

        return ans;
    }
};