    #include <bits/stdc++.h>
    #define ll long long

    using namespace std;

    vector<int> occ(26), cum(26);
    int tot = 0;
    int ppair = 0;
    int impair = 0;

    int mod = 998244353;

    ll dp[26][500001];

    ll dpFact[500001];

    ll FastPower (ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b&1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }
        return ans % mod;
    }

    ll rec(int i, int usedPair) {
        if (usedPair == ppair) return 1;
        if (i==26) return 0;

        ll &ans = dp[i][usedPair];

        if (ans != -1)
            return ans;

        if (occ[i] == 0)
            return ans = rec(i+1, usedPair);
        
        ans = 0;
        int used = i ? cum[i-1] : 0;
        int restPair = ppair - usedPair;
        int usedImpair = used - usedPair;
        int restImpair = impair - usedImpair;

        if (occ[i] <= restPair) {
            ans = (ans + rec(i+1, usedPair+occ[i])) % mod; 
        }

        if (occ[i] <= restImpair) {
            ans = (ans + rec(i+1, usedPair)) % mod; 
        } 

        return ans;
    }

    void solve() {
        freopen("a.txt", "r", stdin);
        int t;
        cin>>t;
        
        dpFact[0] = 1;

        for (int i=1 ; i<=500000 ; i++) {
            dpFact[i] = (i*dpFact[i-1])%mod;
        }

        while(t--) {
            tot = 0;

            ll d = 1;
            for (int i=0 ; i<26 ; i++) {
                cin>>occ[i];
                tot += occ[i];
                cum[i] = tot;
                d = (d * FastPower(dpFact[occ[i]], mod - 2)) % mod;
            }

            ppair = tot&1 ? (tot/2) + 1 : tot/2;
            impair = tot - ppair;

            for (int i=0 ; i<26 ; i++) {
                for (int j=0  ; j<= ppair ; j++)
                    dp[i][j] = -1;
            }

            ll ans = rec(0, 0);

            ans = (ans * dpFact[ppair]) % mod;
            ans = (ans * dpFact[impair]) % mod;

            ans = (ans * d) % mod;

            cout<<ans<<endl;
        }
    }

    int main() {
        solve();
        return 0;
    }