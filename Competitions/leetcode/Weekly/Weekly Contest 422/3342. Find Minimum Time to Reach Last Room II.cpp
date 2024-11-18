#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf (ll)1e18f

using namespace std;

class GraphMaze {
    public:
        const static int N = 750;
        const static int directions = 4;
        vector<vector<int>> graph;
        
        int dx[directions] = {0, 0, -1, 1};
        int dy[directions] = {-1, 1, 0, 0};
        ll dist[N][N];
        int n, m;
    
        GraphMaze(vector<vector<int>> &maze) {
            graph = maze;
            n = graph.size();
            m = graph[0].size();
            initDist();
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

        ll dijkistra() {
            priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
            dist[0][0] = 0;
            pq.push({dist[0][0], 0, 0, 1});

            while(!pq.empty()) {
                vector<ll> parent = pq.top();
                pq.pop();

                ll d = parent[0];
                ll x = parent[1];
                ll y = parent[2];
                ll move = parent[3];

                if (d > dist[x][y])
                    continue;

                for (int dir=0 ; dir<directions ; dir++) {
                    int i = x + dx[dir];
                    int j = y + dy[dir];

                    if (!safe(i, j)) continue;

                    int nextMove = move == 1 ? 2 : 1; // hedhi diff l wahida 3la classical dijkistra
                    ll dd = max(graph[i][j]*1ll, d) + move; // max (node wakteh ywali unlocked bech najem nemchilou, t eli ena feha )
                    if (dist[i][j] > dd) {
                        dist[i][j] = dd;
                        pq.push({dist[i][j], i, j, nextMove});
                    }
                }
            }

            return dist[n-1][m-1];
        }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& v) {
        GraphMaze g = GraphMaze(v);
        return g.dijkistra();
    }
};