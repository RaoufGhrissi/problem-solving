#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<ll,ll>
#define inf (ll)1e9

using namespace std;

class GraphMaze {
    public:
        const static int N = 100;
        const static int directions = 4;
        vector<vector<int>> graph;

        vector<int> match = {1, 0, 3, 2};
        
        int dx[directions] = {0, 0, -1, 1};
        int dy[directions] = {-1, 1, 0, 0};
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

        ll dijkistra()
        {
            priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
            dist[0][0] = 0;
            pq.push({0, 0, 0});

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

                    int cost = 0;
                    int normalDirection = match[graph[x][y]-1];

                    if (dir != normalDirection)
                        cost++;

                    if (safe(i, j) && dist[i][j] > d + cost) {
                        dist[i][j] = d + cost;
                        pq.push({dist[i][j], i, j});
                    }
                }
            }

            return dist[n-1][m-1];
        }
};

class Solution {
public:
    int minCost(vector<vector<int>>& v) {
        GraphMaze g = GraphMaze(v);
        return g.dijkistra();
    }
};