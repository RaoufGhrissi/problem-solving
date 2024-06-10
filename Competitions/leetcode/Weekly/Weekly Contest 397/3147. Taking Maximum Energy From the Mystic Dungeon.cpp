#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& v, int k) {
        
        vector<vector<int>> sum(k);
        
        int ans = -10000;
        int n = v.size();
        for (int i=0 ; i<n ; i++) {
            int id = i%k;
            int sz = sum[id].size();
            int last = sum[id].empty() ? 0 : sum[id][sz-1]; 
            sum[id].push_back(v[i]+last);
        }
        
        for (int i=0 ; i<k ; i++) {
            int sz = sum[i].size();
            
            for (int j=0 ; j<sz ; j++) {
                int res = sum[i][sz-1];
                if (j)
                    res -= sum[i][j-1];
                
                ans = max(ans, res);
            }
        }
        
        return ans;
    }
};