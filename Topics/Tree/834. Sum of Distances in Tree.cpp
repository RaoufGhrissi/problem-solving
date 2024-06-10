#include <bits/stdc++.h>

#define ll long long

using namespace std;

// https://leetcode.com/problems/sum-of-distances-in-tree/

class Solution {
public:
    int memo[30000];
    int sizee[30000];

    int computePaths(int i, int p, vector<vector<int>> &graph) {
        sizee[i] = 1;

        for (auto &child:graph[i]) {
            if (child == p) continue;
            sizee[i] += computePaths(child, i, graph);
        }

        return sizee[i];
    }
    
    int compute(int i, int p, vector<vector<int>> &graph) {
        memo[i] = 0;

        for (auto &child:graph[i]) {
            if (child == p) continue;
            memo[i] += sizee[child] + compute(child, i, graph);
        }

        return memo[i];
    }

    void dfs(int i, int p, vector<vector<int>> &graph, vector<int> &ans) {
        ans[i] = memo[i];

        if (p != -1) {
            int parentMemoWithoutMe = memo[p] - (sizee[i] + memo[i]);
            memo[i] += (int)graph.size() - sizee[i] + parentMemoWithoutMe;
            ans[i] = memo[i];
        }

        for (auto &child:graph[i]) {
            if (child != p) dfs(child, i, graph, ans);    
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto &e:edges) {
            int x = e[0];
            int y = e[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        computePaths(0, -1, graph);
        compute(0, -1, graph);

        vector<int> ans(n, 0);

        dfs(0, -1, graph, ans);

        return ans;
    }
};
