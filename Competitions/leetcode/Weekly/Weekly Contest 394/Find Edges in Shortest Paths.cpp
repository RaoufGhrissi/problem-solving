#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>
using namespace std;

class Graph {
    public:
        vector<set<pp>> edges;
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
            dist[i] = 1e18;
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
    
    void dijkistra()
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        dist[0] = 0;
        pq.push({dist[0], 0});
        vector<int> ans;

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
                if (dist[child] > dFromParentToChild + d)
                {
                    dist[child] = dFromParentToChild + d;
                    pq.push({dist[child], child});
                }
            }
        }
    }

    void backtrack(int p, vector<bool> &ans, map<pp, int> &pos) {
        for (auto &child:edges[p]) {
            int x = child.first;
            int w = child.second;

            if (dist[x] + w == dist[p]) {
                pp pr = {min(x, p), max(x, p)};
                if (pos.count(pr)) ans[pos[pr]] = 1;
                backtrack(x, ans, pos);
            }
        }
    }
};

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        map<pp, int> pos;
        Graph g = Graph(n, 0);
        int m = edges.size();
        for (int i=0 ; i<m ; i++) {
            vector<int> e = edges[i];
            int x = e[0], y = e[1], w = e[2];
            if (x>y) swap(x, y);
            g.add(x, y, w);
            pos[{x, y}] = i;
        }

        g.dijkistra();
        vector<bool> ans(m, 0);
        g.backtrack(n-1, ans, pos);

        return ans;
    }
};