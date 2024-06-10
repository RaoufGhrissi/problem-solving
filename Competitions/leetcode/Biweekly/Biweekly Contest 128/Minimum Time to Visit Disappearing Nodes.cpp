#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define INF 1e9
#define pp pair<int,int>

using namespace std;

class Graph {
    public:
        vector<set<pp>> edges;
        int n;
        bool directed;
        vector<int> dist;
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

    void add(int a, int b, int w = 1) {
        edges[a].insert({b, w});

        if (!directed) {
            edges[b].insert({a, w});
        }
    }

    bool isCyclic(int node) {
        vis[node] = 1;
        anc[node] = 1;

        for (auto &c:edges[node]) {
            int child = c.first;

            if (anc[child])
                return true;

            if (!vis[child] && isCyclic(child))
                return true;
        }

        anc[node] = 0;

        return false;
    }

    void dijkistra(int node, vector<int> &dsp)
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        dist[node] = 0;
        pq.push({dist[node], node});

        while(!pq.empty())
        {
            pp parent = pq.top();
            pq.pop();

            int d = parent.first;
            ll index = parent.second;

            if (d>dist[index])
                continue;

            for (auto childPair:edges[index])
            {
                ll child = childPair.first;
                ll dFromParentToChild = childPair.second;
                ll newD = dFromParentToChild + d;
                if (newD >= dsp[child]) continue;
                if (dist[child] > newD)
                {
                    dist[child] = newD;
                    pq.push({dist[child], child});
                }
            }
        }
    } 
};

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& d) {
        Graph g = Graph(n, 0);

        for (auto &a:edges) {
            g.add(a[0], a[1], a[2]);
        }

        g.dijkistra(0, d);

        for (int i=0 ; i<n ; i++) {
            if (g.dist[i] == INF) g.dist[i] = -1;
        }

        return g.dist;
    }
};