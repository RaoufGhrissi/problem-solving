#include <bits/stdc++.h>

#define pp pair<int,int>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<pp>> &graph, vector<int> &cum, vector<stack<int>> &colorIds, set<pp> &mxIndex, vector<pp> &mx, vector<int> &colors, int parent = -1, int weight = 0) {
        int color = colors[node];

        if (!colorIds[color].empty()) {
            mxIndex.insert({colorIds[color].top(), color});
        }

        int n = cum.size();
        int cnt = n+1;
        cum.push_back(weight);
        if (n > 0) {
            cum[n] += cum[n-1];
        }

        mx[node] = {cum[n], cnt};
        if (mxIndex.size() > 1) {
            auto it = mxIndex.rbegin();
            it++;
            int x = (*it).first + 1;
            mx[node].first -= cum[x];
            mx[node].second -= x;
        }

        colorIds[color].push(n);

        for (pp &childW:graph[node]) {
            int child = childW.first;
            int w = childW.second;

            if (child != parent) {
                dfs(child, graph, cum, colorIds, mxIndex, mx, colors, node, w);
            }
        }

        cum.pop_back();
        colorIds[color].pop();

        if (!colorIds[color].empty()) {
            mxIndex.erase({colorIds[color].top(), color});
        }
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pp>> graph(n);

        int mxColor = *max_element(nums.begin(), nums.end());

        for (auto &e:edges) {
            int x = e[0];
            int y = e[1];
            int l = e[2];

            graph[x].push_back({y, l});
            graph[y].push_back({x, l});
        }
 
        vector<int> cum;
        vector<stack<int>> colorIds(mxColor+1);
        set<pp> mxIndex;
        vector<pp> mx(n);

        dfs(0, graph, cum, colorIds, mxIndex, mx, nums);
        int mxx = 0;
        int mi = 1e9;

        for (int i=0; i<n; i++) {
            mxx = max(mxx, mx[i].first);
        }

        for (int i=0 ;i<n; i++) {
            if (mx[i].first == mxx) {
                mi = min(mi, mx[i].second);
            }
        }

        return {mxx, mi};
    }
};
