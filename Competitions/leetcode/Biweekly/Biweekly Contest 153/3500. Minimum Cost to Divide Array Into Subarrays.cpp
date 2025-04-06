#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll minimumCost(vector<int>& v, vector<int>& cum, int k) { 
        int n = v.size();
        
        for (int i=1 ; i<n ; i++) {
            cum[i] += cum[i-1];
            v[i] += v[i-1];
        }

        vector<ll> dp(n);
        for (int i=0 ; i<n ; i++) {
            dp[i] = v[i] * 1ll * cum[i] + k*1ll*cum[n-1];
            for (int j=0 ; j<i ; j++) {
                dp[i] = min(dp[i], dp[j] + v[i] * 1ll * (cum[i] - cum[j]) + k*1ll*(cum[n-1] - cum[j]));
            }
        }

        return dp[n-1];
    }
};