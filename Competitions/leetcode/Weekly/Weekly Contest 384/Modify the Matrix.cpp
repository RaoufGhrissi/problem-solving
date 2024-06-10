#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& v) {
        map<int,int> mx;
        int n = v.size();
        int m = v[0].size();
        
        for (int i=0 ; i<n ; i++) {
            for (int col=0 ; col<m ; col++) {
                mx[col] = mx.count(col) ? max(mx[col], v[i][col]) : v[i][col];
            }
        }
        
        for (int i=0 ; i<n ; i++) {
            for (int col=0 ; col<m ; col++) {
                if (v[i][col] != -1) continue;
                v[i][col] = mx[col];
            }
        }
        
        return v;
    }
};