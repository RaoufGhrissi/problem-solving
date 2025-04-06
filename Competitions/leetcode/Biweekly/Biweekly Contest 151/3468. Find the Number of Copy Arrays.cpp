#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countArrays(vector<int>& o, vector<vector<int>>& b) {
        int l = b[0][0];
        int r = b[0][1];
        
        int n = b.size();
        
        for (int i=1 ; i<n ; i++) {
            int s = b[i][0];
            int e = b[i][1];
            int diff = o[i]-o[i-1];
            
            int ll = l+diff;
            int rr = r+diff;
            
            if (rr<s || e<ll) return 0;
            
            l = max(s, ll);
            r = min(e, rr);
        }
        
        return r-l+1; 
    }
};