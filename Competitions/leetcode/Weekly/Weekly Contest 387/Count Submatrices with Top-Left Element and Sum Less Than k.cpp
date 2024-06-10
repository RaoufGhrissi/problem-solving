#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();
        
        for (int i=0 ; i<n ; i++) {
            for (int j=1 ; j<m ; j++) {
                v[i][j] += v[i][j-1];
            }
        }
        
        int ans = 0;
        for (int j=0 ; j<m ; j++) {
            for (int i=0 ; i<n ; i++) {
                if (i)
                    v[i][j] += v[i-1][j];
                
                if (v[i][j] <= k)
                    ans++;
            }
        }
        
        return ans;
    }
};