#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pp pair<ll,ll>
#define INF (ll)1e18

using namespace std;

class Graph {
    public:
        vector<vector<pp>> edges;
        int n;
        bool directed;
        vector<ll> dist;
        vector<bool> vis;
        vector<bool> anc;

    Graph(int _n, bool _directed = true) {
        n = _n;
        edges.resize(n);
        directed = _directed;
        init();
    }

    void init() {
        dist.resize(n);
        vis.resize(n);
        anc.resize(n);

        for (int i=0 ; i<n ; i++) {
            dist[i] = INF;
            vis[i] = 0;
            anc[i] = 0;
        }
    }

    void add(int a, int b, int w) {
        edges[a].push_back({b, w});

        if (!directed) {
            edges[b].push_back({a, w});
        }
    }

    void dfs(int node) {
        vis[node] = 1;

        for (auto &c:edges[node]) {
            int child = c.first;

            if (!vis[child])
                dfs(child);
        }
    }

    bool isCyclic(int node) {
        vis[node] = 1;
        anc[node] = 1;

        for (auto &c:edges[node]) {
            int child = c.first;

            if (anc[node])
                return true;

            if (!vis[child] && isCyclic(child))
                return true;
        }

        anc[node] = 0;

        return false;
    }

    vector<int> dijkistra(int node)
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        dist[node] = 0;
        pq.push({dist[node], node});
        vector<int> ans;

        while(!pq.empty())
        {
            pp parent = pq.top();
            pq.pop();

            int d = parent.first;
            ll index = parent.second;

            if (d>dist[index])
                continue;

            ans.push_back(index);

            for (auto childPair:edges[index])
            {
                ll child = childPair.first;
                ll dFromParentToChild = childPair.second;
                if (dist[child] > dFromParentToChild && dFromParentToChild >= d)
                {
                    dist[child] = dFromParentToChild;
                    pq.push({dist[child], child});
                }

            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    } 
};