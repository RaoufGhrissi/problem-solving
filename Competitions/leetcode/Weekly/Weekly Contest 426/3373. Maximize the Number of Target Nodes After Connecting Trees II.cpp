#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    pp dfs(int node, int parent, vector<vector<int>> &graph, vector<pp> &memo) {
        memo[node] = {parent == -1 ? graph[node].size() : graph[node].size() - 1, 0};

        for (int &child:graph[node]) {
            if (child == parent) continue;

            auto [odd, even] = dfs(child, node, graph, memo);

            memo[node].first += even;
            memo[node].second += odd;
        }

        return memo[node];
    }

    void dfs0(int node, int parent, vector<vector<int>> &graph, vector<pp> &memo) {
        if (parent != -1) {
            memo[node] = { memo[parent].second + 1, memo[parent].first - 1};
        }
        for (int &child:graph[node]) {
            if (child != parent)
                dfs0(child, node, graph, memo);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;

        vector<vector<int>> graph1(n), graph2(m);
        vector<pp> memo1(n), memo2(m);
        
        for (auto &e:edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }

        for (auto &e:edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        dfs(0, -1, graph1, memo1);
        dfs0(0, -1, graph1, memo1);

        dfs(0, -1, graph2, memo2);
        dfs0(0, -1, graph2, memo2);

        int mid = 0;
        for (int i=1 ; i<m ; i++) {
            if (memo2[i].first > memo2[mid].first)
                mid = i;
        }

        vector<int> ans(n);

        for (int i=0 ; i<n ; i++) {
            ans[i] = memo1[i].second + 1 + memo2[mid].first;
        }

        return ans;
    }
};