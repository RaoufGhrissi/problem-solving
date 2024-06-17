#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    ll dp[100000];
    map<int,int> occ;
    vector<int> u;
    vector<int> next;
    int n;
    
    ll rec(int i) {
        if (i==n) return 0;
        
        ll &ans = dp[i];
        if (ans != -1) return ans;
        
        ans = rec(i+1);
        return ans = max(ans, u[i]*1ll*occ[u[i]] + rec(next[i]));
    }
    
    long long maximumTotalDamage(vector<int>& v) {
        sort(v.begin(), v.end());
        for (auto &a:v) {
            if (!occ.count(a))
                u.push_back(a);
            
            occ[a]++;
        }

        n = u.size();
        next.resize(n, n);

        for (int i=0 ; i<n ; i++) {
            int id = lower_bound(u.begin(), u.end(), u[i]+3) - u.begin();
            next[i] = id;
        }

        memset(dp, -1, sizeof dp);
        return rec(0);
        
    }
};