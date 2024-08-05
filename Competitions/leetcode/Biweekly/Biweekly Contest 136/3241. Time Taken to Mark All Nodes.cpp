#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<int,int>
#define INF (ll)1e18

using namespace std;

class Graph {
    public:
        vector<vector<pp>> edges;
        vector<vector<pp>> dist;
        vector<int> ans;
        int n;
        bool directed;
        vector<bool> vis;

    Graph(int _n, bool _directed = true) {
        n = _n;
        directed = _directed;
        init();
    }

    void add_dist(int node, int d, int child) {
        if (dist[node].size() < 2) {
            dist[node].push_back({ d, child });
        } else if (d > dist[node][0].first) {
            dist[node][0] = { d, child };
        }
        
        if (dist[node].size() == 2 && dist[node][0].first > dist[node][1].first) {
            swap(dist[node][0], dist[node][1]);
        }
    }

    void init() {
        edges.resize(n);
        dist.resize(n);
        vis.resize(n);
        ans.resize(n);

        for (int i=0 ; i<n ; i++) {
            vis[i] = 0;
            ans[i] = 0;
        }
    }

    void add(int a, int b, int w) {
        edges[a].push_back({b, w});

        if (!directed) {
            edges[b].push_back({a, w});
        }
    }

    int dfs(int node) {
        vis[node] = 1;
        
        for (auto &c:edges[node]) {
            int child = c.first;
            if (vis[child]) continue;
            
            int d = c.second + dfs(child);

            add_dist(node, d, child);
            ans[node] = max(ans[node], d);
        }

        return ans[node];
    }

    void dfs0(int node) {
        vis[node] = 1;
        for (auto &c:edges[node]) {
            int child = c.first;

            if (vis[child]) {
                int d = c.second;

                if (dist[child].size() == 2) {
                    d += dist[child][1].second == node ? dist[child][0].first : dist[child][1].first;
                } else if (dist[child].size() == 1) {
                    d += dist[child][0].second == node ? 0 : dist[child][0].first;
                }

                add_dist(node, d, child);
                ans[node] = max(ans[node], d);
            }
        }

        for (auto &c:edges[node]) {
            int child = c.first;

            if (!vis[child]) {
                dfs0(child);
            }
        }
    }
};

class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& e) {
        int n = e.size() + 1;
        Graph graph = Graph(n);

        for (auto &ee:e) {
            int x = ee[0];
            int y = ee[1];

            graph.add(x, y, y&1 ? 1 : 2);
            graph.add(y, x, x&1 ? 1 : 2);
        }

        graph.dfs(0);

        for (int i=0 ; i<n ; i++)
            graph.vis[i] = 0;

        graph.dfs0(0);

        return graph.ans;
    }
};