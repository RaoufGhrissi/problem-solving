#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<ll,ll>
#define inf (ll)1e18f

using namespace std;

class GraphMaze {
    public:
        const static int N = 107;
        const static int directions = 3;
        vector<vector<int>> graph;
        
        int dx[directions] = {1, 1, 1};
        int dy[directions] = {-1, 0, 1};
        bool vis[N][N];
        ll dist[N][N];
        int n, m;
    
        GraphMaze(vector<vector<int>> &maze) {
            graph = maze;
            n = graph.size();
            m = graph[0].size();
            initVis();            
            initDist();
        }

        void initVis() {
            memset(vis, 0, sizeof vis);
        }
        
        void initDist() {
            for (int i=0 ; i<n ; i++) {
                for (int j=0 ; j<m ; j++) {
                    dist[i][j] = inf;
                }
            }
        }

        bool safe(int i, int j) {
            return i>-1 && i<n && j>-1 && j<m;
        }

        ll dijkistra(vector<pp> entry)
        {
            priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

            for (auto &cell:entry) {
                ll x = cell.first;
                ll y = cell.second;
                dist[x][y] = graph[x][y];
                pq.push({dist[x][y], x, y});
            }

            while(!pq.empty())
            {
                vector<ll> parent = pq.top();
                pq.pop();

                ll d = parent[0];
                ll x = parent[1];
                ll y = parent[2];

                if (d > dist[x][y])
                    continue;

                for (int dir=0 ; dir<directions ; dir++) {
                    int i = x + dx[dir];
                    int j = y + dy[dir];

                    if (safe(i, j) && dist[i][j] > dist[x][y] + graph[i][j]) {
                        dist[i][j] = dist[x][y] + graph[i][j];
                        pq.push({dist[i][j], i, j});
                    }
                }
            }

            ll ans = inf;
            for (int i=0 ; i<m ; i++) {
                ans = min(ans, dist[n-1][i]);
            }

            return ans;
        }
};

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        GraphMaze graph = GraphMaze(v);
        int m = v[0].size();
        vector<pp> entry;
        for (int col=0 ; col<m ; col++)
            entry.pb({0, col});
        return graph.dijkistra(entry);
    }
};