#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
#define ll long long
#define mod (int)(1e9 + 7)

using namespace std;

class Cnk {
    public:
        ll dp[1001][1001];

        Cnk() {
            memset(dp, -1, sizeof dp);
        }

        ll compute(int n, int k) {
            if (!k)
                return 1;

            if (!n)
                return 0;

            if (dp[n][k] != -1)
                return dp[n][k];

            return dp[n][k] = (compute(n-1, k)%mod + compute(n-1, k-1)%mod)%mod;
        }
};

class Stirling {            
    public:
        ll dp[1001][1001];

        Stirling() {
            memset(dp, 0, sizeof dp);

            dp[0][0] = 1;
            for (int i = 1; i <= 1000; i++)
                for (int j = 1; j <= i; j++)
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] * j) % mod;
        }
};

ll FastPower(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b&1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans % mod;
}

class Fact {
    public:
        ll dp[1001];

        Fact() {
            memset(dp, -1, sizeof dp);
        }

        ll compute(ll n) {
            if (!n)
                return 1;

            if (dp[n] != -1)
                return dp[n];

            return dp[n] = (n*compute(n-1))%mod;
        }
};

class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        ll ans = 0;
        Cnk cnk = Cnk();
        Stirling stirling = Stirling();
        Fact fact = Fact();

        fact.compute(1000);

        for (int band=1 ; band<=min(x, n) ; band++) {
            ans += ((cnk.compute(x, band) * stirling.dp[n][band])%mod * fact.dp[band])%mod * FastPower(y, band);
            ans %= mod;
        }

        return ans;
    }
};