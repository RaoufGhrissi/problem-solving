#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Cnk {
    public:
        ll dp[41][41];
        int mod = 1e9 + 7;

        Cnk() {
            memset(dp, -1, sizeof dp);
        }

        ll compute(int n, int k) {
            if (k > n) return 0;
            if (!k) return 1;
            if (!n) return 0;

            ll &ans = dp[n][k];
            if (ans != -1)
                return ans;

            return ans = (compute(n-1, k-1)%mod + compute(n-1, k)%mod)%mod;
        }
};

class Solution {
public:
    int tot = 0;
    ll dp[10][9*40 + 1][41];
    ll mod = 1e9 + 7;
    int totImp, totP;

    int occ[10];
    int cum[10];

    ll rec(int i, int sm, int p, Cnk &cnk) {
        if (i == 10) {
            if (p == totP) {
                if (sm*2 != tot)
                    return 0;
                
                return 1;
            }

            return 0;
        }

        ll &ans = dp[i][sm][p];
        if (ans != -1)
            return ans;

        if (!occ[i])
            return ans = rec(i+1, sm, p, cnk);

        int imp = totImp;
        if (i) {
            imp -= cum[i-1]-p;
        }

        if (imp < 0) return 0;

        int restP = totP - p;
        ans = 0;
        for (int x=0 ; x<=min(occ[i], restP) ; x++) {
            if (imp >= occ[i]-x)
                ans += ((cnk.compute(restP, x) * rec(i+1, sm + i*x, p+x, cnk))%mod * cnk.compute(imp, occ[i]-x))%mod;
            ans %= mod;
        }

        return ans;
    }

    int countBalancedPermutations(string s) {
        memset(occ, 0, sizeof occ);
        memset(cum, 0, sizeof cum);

        for (char &c:s) {
            int x = c - '0';
            occ[x]++;
            tot += x;
        }

        for (int i=0 ; i<10 ; i++) {
            cum[i] = occ[i];
            if (i)
                cum[i] += cum[i-1];
        }

        memset(dp, -1, sizeof dp);

        Cnk cnk = Cnk();

        int n = s.size();
        totP = (n+1)/2;
        totImp = n-totP;

        return rec(0, 0, 0, cnk);
    }
};
