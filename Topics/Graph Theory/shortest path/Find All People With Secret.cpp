//https://leetcode.com/problems/find-all-people-with-secret/

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

    Graph(int _n, bool _directed = true) {
        n = _n;
        edges.resize(n);
        directed = _directed;
        init();
    }

    void init() {
        dist.resize(n);
        for (int i=0 ; i<n ; i++)
            dist[i] = INF;
    }

    void add(int a, int b, int w) {
        edges[a].push_back({b, w});

        if (!directed) {
            edges[b].push_back({a, w});
        }
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

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& v, int f) {
        Graph g = Graph(n, false);

        g.add(0, f, 0);
        for (auto &a:v) {
            g.add(a[0], a[1], a[2]);
        }
        
        return g.dijkistra(0);
    }
};

