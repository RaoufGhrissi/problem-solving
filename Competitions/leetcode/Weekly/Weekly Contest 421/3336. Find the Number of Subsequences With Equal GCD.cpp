#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    int dp[200][201][201];
    int gcd[201][201];

    const static int mod = 1e9 + 7;

    int rec(int i, int g1, int g2, vector<int>& v) {
        if (i == v.size()) return g1 && (g1 == g2);

        int &ans = dp[i][g1][g2];

        if (ans != -1) return ans;

        return ans = ((rec(i+1, g1, g2, v)%mod + 
            rec(i+1, !g1 ? v[i] : gcd[g1][v[i]], g2, v)%mod)%mod +
            rec(i+1, g1, !g2 ? v[i] : gcd[g2][v[i]], v)%mod)%mod;
    }

    int subsequencePairCount(vector<int>& v) {
        for (int i=1 ; i<=200 ; i++) {
            for (int j=1 ; j<=200 ; j++) {
                gcd[i][j] = __gcd(i, j);
            }
        }

        memset(dp, -1, sizeof dp);
        return rec(0, 0, 0, v);
    }
};