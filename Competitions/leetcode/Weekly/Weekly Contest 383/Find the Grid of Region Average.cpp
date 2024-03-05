#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool safe(int i, int j, int n, int m) {
        return i>=0 && j>=0 && i<n && j<m;    
    }
    
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    vector<vector<int>> resultGrid(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        set<pair<int,int>> notGood[n][m];
        vector<int> regions[n][m];
        vector<vector<int>> ans(n, vector<int>(m));
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                for (int d=0 ; d<4 ; d++) {
                    int di = i+dx[d];
                    int dj = j+dy[d];
                    
                    if (safe(di, dj, n, m) && abs(v[i][j] - v[di][dj]) > t) {
                        notGood[i][j].insert({di, dj});
                    }
                }
            }
        }
        
        for (int i=0 ; i<n-2 ; i++) {
            for (int j=0 ; j<m-2 ; j++) {
                bool isValidRegion = 1;
                int tot = 0;
                for (int x=i ; x<i+3 ; x++) {
                    for (int y=j ; y<j+3 ; y++) {
                        tot += v[x][y];
                        for (auto &a:notGood[x][y]) {
                            int xx = a.first;
                            int yy = a.second;
                            
                            if (xx >= i && xx<i+3 && yy>=j && yy<j+3) {
                                isValidRegion = 0;
                                break;
                            }
                        }
                    }
                    if (!isValidRegion)
                        break;
                }
                
                if (!isValidRegion)
                    continue;
                
                for (int x=i ; x<i+3 ; x++) {
                    for (int y=j ; y<j+3 ; y++) {
                        regions[x][y].push_back(tot/9);
                    }
                }
            }
        }
        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                int sz = regions[i][j].size();
                if (regions[i][j].size() == 0) {
                    ans[i][j] = v[i][j];
                    continue;
                }
                
                int sm = 0;
                for (auto &a:regions[i][j])
                    sm += a;
                
                
                ans[i][j] = sm/sz;
            }
        }
        
        
        return ans;
    }
};