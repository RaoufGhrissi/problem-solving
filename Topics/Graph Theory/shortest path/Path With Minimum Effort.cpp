#include <bits/stdc++.h>

using namespace std;
#define pp pair<int, pair<int,int>>
#define inf 1e7
class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int n, m;
    int dist[100][100];

    bool safe(int i, int j) {
        return i>-1 && i<n && j>-1 && j<m;
    }

    int bfs(int px, int py, vector<vector<int>>& v) {
        priority_queue<pp, vector<pp>, greater<pp>> q;
        for (int i=0 ; i<n ; i++)
        {
            for (int j=0; j<m ; j++)
                dist[i][j] = inf;
        }
        dist[px][py] = 0;
        q.push({dist[px][py], {px, py}});
        
        while(!q.empty()) {
            pp p = q.top();
            int h = p.first;
            int i = p.second.first;
            int j = p.second.second;
            q.pop();

            if (h > dist[i][j])
                continue;

            for (int c=0 ; c<4 ; c++)
            {
                int x = i + dx[c];
                int y = j + dy[c];
                if (safe(x, y) && max(abs(v[x][y] - v[i][j]), dist[i][j]) < dist[x][y]) {
                    dist[x][y] = max(abs(v[x][y] - v[i][j]), dist[i][j]);
                    q.push({dist[x][y], {x,y}});
                }
            }
        }

        return dist[n-1][m-1];
    }

    int minimumEffortPath(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        return bfs(0, 0, v);
    }
};