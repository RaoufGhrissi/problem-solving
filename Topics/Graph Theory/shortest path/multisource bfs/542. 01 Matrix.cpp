#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int dir = 4;
    int dx[dir] = {0, 0, 1, -1};
    int dy[dir] = {-1, 1, 0, 0};

    bool safe(int i, int j, int n, int m) {
        return i>-1 && i<n && j>-1 && j<m;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& t) {
        int n = t.size();
        int m = t[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));

        queue<vector<int>> q;

        for (int i=0 ; i<n ; i++) {
            for (int j=0; j<m; j++) {
                if (!t[i][j]) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            int i = p[0];
            int j = p[1];

            for (int dd=0 ; dd<dir ; dd++) {
                int xx = i + dx[dd];
                int yy = j + dy[dd];
                if (safe(xx, yy, n, m) && t[xx][yy] && (dist[xx][yy] > (1 + dist[i][j]))) {
                    dist[xx][yy] = 1 + dist[i][j];
                    q.push({xx, yy});
                }
            }
        }

        return dist;
    }
};