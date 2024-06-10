#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& v) {
        map<int, int> occ;
        for (auto &a:v)
            occ[a]++;
        
        vector<int> t;
        for (auto &a:occ) {
            t.push_back(a.first);
        }
        
        int n = t.size();
        map<int, int> dp;
        int ans = 1;
        if (occ.count(1))
            ans = occ[1]&1 ? occ[1] : occ[1]-1;
        
        for (int i=0 ; i<n ; i++) {
            int target = sqrt(t[i]);
            
            if (pow(target, 2) != t[i] || !occ.count(target) || occ[target] < 2) {
                dp[t[i]] = 1;
                continue;
            }
            
            dp[t[i]] = 1 + dp[target]; // longest sequence with t[i] its middle
            
            ans = max(ans, 2*dp[t[i]]-1);
        }
        
        return ans;
    }
};