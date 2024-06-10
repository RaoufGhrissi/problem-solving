#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll dp[1001][1001][2];
    int mod = 1e9 + 7;
    
    int numberOfStableArrays(int zero, int one, int limit) {
        ll prefix0[1001][1001] = {0};
        ll prefix1[1001][1001] = {0};

        memset(dp, 0, sizeof dp);

        for (int z=0 ; z<=zero ; z++) {
            for (int o=0 ; o<=one ; o++) {

                if (!o && !z) {
                    dp[0][0][0] = 1;
                    prefix0[0][0] = 1;

                    dp[0][0][1] = 1;
                    prefix1[0][0] = 1;
                    
                    continue;
                }

                if (z) {
                    dp[z][o][1] = prefix0[z-1][o];
                    int l = z-min(limit, z);
                    if (l)
                        dp[z][o][1] -= prefix0[l-1][o];

                    dp[z][o][1] %= mod;
                }
                
                if (o) {
                    dp[z][o][0] = prefix1[z][o-1];
                    int l = o-min(o, limit);
                    if (l)
                        dp[z][o][0] -= prefix1[z][l-1];

                    dp[z][o][0] %= mod;
                }
                
                prefix1[z][o] = dp[z][o][1]; // v[i]
                if (o)
                    prefix1[z][o] += prefix1[z][o-1]; // if i>0 += v[i-1]
                
                prefix0[z][o] = dp[z][o][0];
                if (z)
                    prefix0[z][o] += prefix0[z-1][o];
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1])%mod;
    }
};

int main() {    
    cout<<Solution().numberOfStableArrays(1, 1, 2);
    return 0;
}