#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<ll,ll>
#define INF (ll)1e18

using namespace std;

#define inf 1e9 + 6
#define pp pair<int,int>

class Graph {
    public:
        vector<vector<pp>> graph;
        int n;
        bool directed;
        vector<int> dist;
        vector<bool> vis;
        vector<bool> anc;

    Graph(int _n, vector<vector<int>> &edges, bool _directed = false) {
        n = _n;
        directed = _directed;
        init();

        for (auto &e:edges) {
            add(e[0], e[1], e[2]+1);
        }
    }

    void init() {
        graph.resize(n);
        dist.resize(n);
        vis.resize(n);
        anc.resize(n);

        for (int i=0 ; i<n ; i++) {
            dist[i] = inf;
            vis[i] = 0;
            anc[i] = 0;
        }
    }

    void add(int a, int b, int w = 1) {
        graph[a].push_back({b, w});

        if (!directed) {
            graph[b].push_back({a, w});
        }
    }

    void dfs(int node) {
        vis[node] = 1;

        for (auto &[child, cost]:graph[node]) {
            if (!vis[child]) {
                dfs(child);
            }
        }
    }

    void dijkistra(int node) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        dist[node] = 0;
        pq.push({dist[node], node});
        vector<int> ans;

        while(!pq.empty()) {
            pp parent = pq.top();
            pq.pop();

            int d = parent.first;
            int index = parent.second;

            if (d > dist[index])
                continue;

            for (auto childPair:graph[index]) {
                int child = childPair.first;
                int dFromParentToChild = childPair.second;
                if (dist[child] > dFromParentToChild + d) {
                    dist[child] = dFromParentToChild + d;
                    pq.push({dist[child], child});
                }

            }
        }
    } 
};

int main() {

}