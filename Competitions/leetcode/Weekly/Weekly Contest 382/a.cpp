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
    map<pp, map<int,ll>> dp; // key = {i, k}, value : {0: res mta3 0, 1: res mta3 1}
    // isStart = 1 mafama hata range mahloul
    //isStart = 0 fama range ma7loul
    
    ll rec(int i, int k, int isStart, vector<int> &v) {
        if (i==v.size()) {
            if (!isStart && k==1) {
                return 0;
            }
            
            return -1e15;
        }
        
        if (!k) {
            return 0;
        }
        
        pp p = {i, k};
        if (dp.count(p) && dp[p].count(isStart)) {
            return dp[p][isStart];
        }
        
        ll &ans = dp[p][isStart];
        ans = 1e15;
        int coef = k&1 ? 1 : -1; // idha impair coef = 1
        if (isStart) {
            ans = min({
                ans,
                rec(i+1, k, 1, v),
                coef*k*v[i] + rec(i+1, k, 0, v),
            });
        } else {
            ans = min({
                ans,
                coef*k*v[i] + rec(i+1, k, 0, v),
                rec(i, k-1, 1, v),
            });
        }
        
        return ans;
    }
    
    ll maximumStrength(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(k, vector<ll>(2, -1)));
        return rec(0, k, 1, v);
    }
};

int main() {
    vector<int> v = {1,2,3,-1,2};
    cout<<Solution().maximumStrength(v, 3);

    return 0;
}