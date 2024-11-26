#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    int dp[800][801][2];

    int rec(int i, int ones, int less, string &s) {
        if (i == s.size()) return less && !ones;

        int &ans = dp[i][ones][less];

        if (ans != -1)
            return ans;

        if (s[i] == '1') {
            ans = rec(i+1, ones, 1, s)%mod;
            if (ones)
                ans = (ans + rec(i+1, ones-1, less, s)%mod)%mod;
        } else {
            ans = rec(i+1, ones, less, s)%mod;

            if (less && ones)
                ans = (ans + rec(i+1, ones-1, less, s)%mod)%mod;
        }

        return ans;
    }

    int countKReducibleNumbers(string s, int k) {
        int n = s.size();

        ll ans = 0;
        memset(dp, -1, sizeof dp);

        for (int num=800 ; num>0 ; num--) {
            int kk = k-1;
            int nm = num;
            
            while(nm > 1 && kk > 0) {
                nm = __builtin_popcount(nm);
                kk--;
            }

            if (nm > 1) continue;
            ans = (ans + rec(0, num, 0, s)) % mod;
        }

        return ans;
    }
};
