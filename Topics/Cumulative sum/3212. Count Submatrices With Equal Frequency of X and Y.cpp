#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& v) {
        int n = v.size(), m = v[0].size();
        int ans = 0;
        
        vector<vector<int>> x(n, vector<int>(m, 0)); 
        vector<vector<int>> y(n, vector<int>(m, 0));
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0; j<m ; j++) {
                if (v[i][j] == 'X') {
                    x[i][j] = 1;
                } else if (v[i][j] == 'Y') {
                    y[i][j] = 1;
                }
                
                if (!j) continue;
                
                x[i][j] += x[i][j-1];
                y[i][j] += y[i][j-1];
            }
        }
        
        for (int i=1 ; i<n ; i++) {
            for (int j=0; j<m ; j++) {
                x[i][j] += x[i-1][j];
                y[i][j] += y[i-1][j];
            }
        }
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (x[i][j] > 0 && x[i][j] == y[i][j])
                    ans++;
            }
        }
        
        
        
        return ans;
    }
};