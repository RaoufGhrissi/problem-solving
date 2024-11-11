#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<set<int>> graph;
    vector<set<int>> cpy;

    vector<int> ans;

    stack<int> anc[26];

    void dfs(int root, string &s, int parent = -1) {
        int id = s[root] - 'a';

        if (!anc[id].empty()) {
            int t = anc[id].top();
            
            cpy[parent].erase(root);
            cpy[t].insert(root);
        }

        anc[id].push(root);

        for (auto &child:graph[root]) {
            dfs(child, s, root);
        }

        anc[id].pop();
    }

    int dfsCount(int root) {
        ans[root] = 1;

        for (auto &child:cpy[root]) {
            ans[root] += dfsCount(child);
        }

        return ans[root];
    }

    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();

        ans.resize(n);
        graph.resize(n);

        for (int i=1 ; i<n ; i++) {
            graph[p[i]].insert(i);
        }

        cpy = graph;

        dfs(0, s);

        dfsCount(0);

        return ans;
    }
};  