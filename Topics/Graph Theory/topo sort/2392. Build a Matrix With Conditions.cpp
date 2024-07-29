#include <bits/stdc++.h>

using namespace std;

class Graph {
    public:
    vector<vector<int>> graph;
    vector<int> ind;
    vector<int> order;
    vector<bool> vis, anc;
    bool hasFakeNode = 0;
    int n;

    Graph(int _n) {
        n = _n+1;
        graph.resize(n);
        ind.resize(n);
        vis.resize(n);
        anc.resize(n);

        for (int i=0 ; i<n ; i++) {
            ind[i] = 0;
            anc[i] = 0;
            vis[i] = 0;
        }
    }

    void add(int a, int b) {
        graph[a].push_back(b);
        ind[b]++;
    }

    void addFakeNode() {
        for (int i=1 ; i<n ; i++) {
            if (!ind[i]) {
                hasFakeNode = 1;
                graph[0].push_back(i);
            }
        }
    }

    bool dfs(int p) {
        vis[p] = 1;
        anc[p] = 1;

        for (int &child:graph[p]) {
            if (anc[child])
                return 1;

            if (!vis[child] && dfs(child))
                return 1;
        }

        order.push_back(p);
        anc[p] = 0;
        return 0;
    }
};

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& r, vector<vector<int>>& c) {
        Graph lines = Graph(k), cols = Graph(k);

        for (auto &rr:c) {
            cols.add(rr[0], rr[1]);
        }

        cols.addFakeNode();

        if (!cols.hasFakeNode)
            return {};
        
        for (int i=0 ; i<=k ; i++) {
            if (!cols.vis[i] && cols.dfs(i))
                return {};
        }

        cols.order.pop_back();
        reverse(cols.order.begin(), cols.order.end());

        for (auto &rr:r) {
            lines.add(rr[0], rr[1]);
        }

        lines.addFakeNode();
        if (!lines.hasFakeNode)
            return {};
        
        for (int i=0 ; i<=k ; i++) {
            if (!lines.vis[i] && lines.dfs(i))
                return {};
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        vector<int> col(k+1);
        for (int i=0 ; i<k ; i++)
            col[cols.order[i]] = i;

        lines.order.pop_back();
        reverse(lines.order.begin(), lines.order.end());
        
        for (int i=0 ; i<k ; i++) {
            int row = col[lines.order[i]];
            ans[i][row] = lines.order[i];
        }

        return ans;
    }
};