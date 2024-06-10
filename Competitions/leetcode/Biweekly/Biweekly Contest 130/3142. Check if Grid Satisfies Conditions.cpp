#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (i+1<n && v[i][j] != v[i + 1][j]) return 0;
                if (j+1<m && v[i][j] == v[i][j + 1]) return 0;
            }
        }
        
        return 1;
    }
};