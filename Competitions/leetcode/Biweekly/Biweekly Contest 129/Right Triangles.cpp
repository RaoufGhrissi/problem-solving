#include <bits/stdc++.h>

using namespace std;


#define ll long long
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        ll ans = 0;
        
        vector<int> lines(n, 0), cols(m, 0);
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (!v[i][j]) continue;
                
                lines[i]++;
                cols[j]++;
            }
        }
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (!v[i][j]) continue;
                
                ans += (lines[i]-1)*(cols[j]-1);
            }
        }
        
        return ans;
    }
};