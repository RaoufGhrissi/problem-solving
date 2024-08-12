#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>
#define pb push_back

class Solution {
public:
    static const int N = 90;
    int graph[N][N];
    bool vis[N][N];
    int n;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void dfs(int i, int j) 
    {
        vis[i][j]=1;
        for (int c=0 ; c<4 ; c++)
        {
            int x = i+dx[c];
            int y = j+dy[c];

            if (safe(x, y) && !vis[x][y] && !graph[x][y])
                dfs(x, y);
        }
    }

    bool safe(int i, int j)
    {
        return i>-1 && i<3*n && j>-1 && j<3*n;
    }

    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        memset(vis, 0, sizeof vis);
        memset(graph, 0, sizeof graph);

        for (int i=0 ; i<n ; i++)
        {
            for (int j=0 ; j<n ; j++)
            {
                if (grid[i][j] == '/')
                {
                    graph[3*i][3*j+2] = -1;
                    graph[3*i+1][3*j+1] = -1;
                    graph[3*i+2][3*j] = -1;
                } 
                else if (grid[i][j] == '\\')
                {
                    graph[3*i][3*j] = -1;
                    graph[3*i+1][3*j+1] = -1;
                    graph[3*i+2][3*j+2] = -1;
                }
            }
        }

        int ans = 0;
        for (int i=0 ; i<3*n ; i++)
        {
            for (int j=0 ; j<3*n ; j++)
            {
                if (graph[i][j] == -1 || vis[i][j]) continue;
                
                dfs(i, j);
                ans++;
            }
        }

        return ans;
    }
};