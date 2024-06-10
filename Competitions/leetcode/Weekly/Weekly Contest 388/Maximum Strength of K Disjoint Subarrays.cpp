#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<int,int>


//10101010100
//&
//00000000001
//___________
//00000000000

// bech taarfou impair taamel &1 lezem = 1

class Solution {
public:
    //int dp1[2][1e4][2] faisable
    // isStart = 1 mafama hata range mahloul
    //isStart = 0 fama range ma7loul
    
    ll rec(int i, ll k, int isStart, vector<int> &v, vector<vector<vector<ll>>> &dp) {
        if (i==v.size()) {
            if (!isStart && k==1) {
                return 0;
            }
            
            return -1e15;
        }
        
        if (!k) {
            return 0;
        }
        
        if (dp[i][k][isStart] != -1) {
            return dp[i][k][isStart];
        }
        
        ll &ans = dp[i][k][isStart];
        ans = -1e15;
        ll coef = k&1 ? 1 : -1; // idha impair coef = 1
        if (isStart) {
            ans = max({
                ans,
                rec(i+1, k, 1, v, dp),
                coef*k*1ll*v[i] + rec(i+1, k, 0, v, dp),
            });
        } else {
            ans = max({
                ans,
                coef*k*v[i] + rec(i+1, k, 0, v, dp),
                rec(i, k-1, 1, v, dp),
            });
        }
        
        return ans;
    }
    
    ll maximumStrength(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k+1, vector<ll>(2, -1)));
        return rec(0, k, 1, v, dp);
    }
};