#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& v) {
        int n = v.size();
        const int m = 1e5+1;

        int mod = 1e9 + 7;

        map<int, vector<int>> prev;
        int ans = 0;

        for (int i=0 ; i<n ; i++) {
            int cnt = 1;
            int sm = v[i];

            int p = v[i]-1;
            if (prev.count(p)) {
                cnt = (cnt + prev[p][0]) % mod;
                sm = (sm + (prev[p][1] + (prev[p][0] * 1ll * v[i])%mod)%mod)%mod;
            }
            
            p = v[i]+1;
            if (prev.count(p)) {
                cnt = (cnt + prev[p][0]) % mod;
                sm = (sm + (prev[p][1] + (prev[p][0] * 1ll * v[i])%mod)%mod)%mod;
            }
            
            if (!prev.count(v[i]))
                prev[v[i]] = {cnt, sm};
            else {
                prev[v[i]][0] = (prev[v[i]][0] + cnt)%mod;
                prev[v[i]][1] = (prev[v[i]][1] + sm)%mod;
            }

            ans = (ans + sm)%mod;
        }

        return ans;
    }
};