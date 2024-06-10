#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int N = 400;
    int dist[N][N];

    static const int dir = 4;
    int dx[dir] = {0, 0, 1, -1};
    int dy[dir] = {-1, 1, 0, 0};

    void mem0(int val) {
        for(int i=0 ; i<N ; i++) {
            for (int j=0 ; j<N ; j++)
                dist[i][j] = val;
        }
    }

    bool safe(int i, int j, int n, int m) {
        return i>-1 && i<n && j>-1 && j<m;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& v) {
        //multisource bfs

        int n = v.size();

        mem0(1e9);
        queue<vector<int>> q;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (!v[i][j]) continue;
                dist[i][j] = 0;
                q.push({i, j});
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
                if (safe(xx, yy, n, n) && !v[xx][yy] && (dist[xx][yy] > (1 + dist[i][j]))) {
                    dist[xx][yy] = 1 + dist[i][j];
                    q.push({xx, yy});
                }
            }
        }

        priority_queue<vector<int>> pq;

        int t[n][n];
        memset(t, 0, sizeof t);
        t[0][0] = dist[0][0];
        pq.push({t[0][0], 0, 0});

        while(!pq.empty()) {
            vector<int> p = pq.top();
            pq.pop();

            int d = p[0];
            int i = p[1];
            int j = p[2];

            if (t[i][j] > d) continue;
            
            for (int dd=0 ; dd<dir ; dd++) {
                int xx = i + dx[dd];
                int yy = j + dy[dd];

                if (safe(xx, yy, n, n) && (t[xx][yy] < min(d, dist[xx][yy]))) {
                    t[xx][yy] = min(d, dist[xx][yy]);
                    pq.push({t[xx][yy], xx, yy});
                }
            }          
        }

        return t[n-1][n-1];
    }
};