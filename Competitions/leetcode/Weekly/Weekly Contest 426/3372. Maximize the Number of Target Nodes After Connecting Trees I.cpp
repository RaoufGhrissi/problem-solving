#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>> &graph, vector<int> &memo, int level, int &k, int &root) {
        if (level <= k)
            memo[root]++;
        else
            return;

        for (int &child:graph[node]) {
            if (child == parent) continue;

            dfs(child, node, graph, memo, level+1, k, root);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;

        vector<vector<int>> graph1(n), graph2(m);
        vector<int> memo1(n), memo2(m);
        
        for (auto &e:edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }

        for (auto &e:edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        int mid = 0;
        int kk = k-1;
        for (int i=0 ; i<m ; i++) {
            dfs(i, -1, graph2, memo2, 0, kk, i);
            mid = max(mid, memo2[i]);
        }

        vector<int> ans(n);

        for (int i=0 ; i<n ; i++) {
            dfs(i, -1, graph1, memo1, 0, k, i);
            ans[i] = memo1[i] + mid;
        }

        return ans;
    }
};