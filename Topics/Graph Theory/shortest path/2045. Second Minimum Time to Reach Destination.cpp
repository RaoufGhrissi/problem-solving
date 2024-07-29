#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
#define INF (ll)1e9

using namespace std;

class Graph {
    public:
        vector<vector<pp>> edges;
        int n;
        bool directed;
        vector<vector<ll>> dist;

    Graph(int _n, bool _directed = true) {
        n = _n;
        edges.resize(n);
        directed = _directed;
        init();
    }

    void init() {
        dist.resize(n);

        for (int i=0 ; i<n ; i++) {
            dist[i].resize(2);
            dist[i][0] = INF;
            dist[i][1] = INF;
        }
    }

    void add(int a, int b, int w = 1) {
        edges[a].push_back({b, w});

        if (!directed) {
            edges[b].push_back({a, w});
        }
    }

    int djo(int node, int &change, int &time) {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        dist[node][0] = 0;
        pq.push({0, node});

        vector<int> vis(n, 0);

        while(!pq.empty()) {
            pp parent = pq.top();
            pq.pop();

            int d = parent.first;
            ll index = parent.second;

            if (d > dist[index][0] && d > dist[index][1])
                continue;

            for (auto childPair:edges[index]) {
                ll child = childPair.first;
                ll dFromParentToChild = childPair.second;

                int q = d/change;
                ll timeToLeave = q&1 ? change*(q+1) : d;

                ll new_d = timeToLeave + dFromParentToChild;

                if (dist[child][0] > new_d) {
                    dist[child][1] = dist[child][0];
                    dist[child][0] = new_d;
                    pq.push({dist[child][0], child});
                } else if (dist[child][1] > new_d && dist[child][0] != new_d) {
                    dist[child][1] = new_d;
                    pq.push({dist[child][1], child});
                }
            }
        }

        for (int i=0 ; i<n ; i++)
            cout<<dist[i][0]<<" "<<dist[i][1]<<endl;

        if (dist[n-1][1] < INF)
            return dist[n-1][1];

        int q = dist[n-1][0]/change;
        dist[n-1][1] = q&1 ? change*(q+1) : dist[n-1][0];
        dist[n-1][1] += time;

        q = dist[n-1][1]/change;
        dist[n-1][1] = q&1 ? change*(q+1) : dist[n-1][1];
        return dist[n-1][1] + time;
    } 
};

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        Graph graph = Graph(n, 0);

        for (auto &e:edges)
            graph.add(e[0]-1, e[1]-1, time);

        return graph.djo(0, change, time);
    }
};