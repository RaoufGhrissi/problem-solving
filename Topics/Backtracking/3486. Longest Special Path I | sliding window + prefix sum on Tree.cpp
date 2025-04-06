#include <bits/stdc++.h>

#define pp pair<int,int>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<pp>> &graph, vector<int> &cum, vector<stack<int>> &colorIds, priority_queue<pp> &mxIndex, vector<pp> &mx, vector<int> &colors, int parent = -1, int weight = 0) {
        int color = colors[node];
        
        while(!mxIndex.empty()) {
            if (colorIds[mxIndex.top().second].size() < 2) {
                mxIndex.pop();
            } else {
                int last = colorIds[mxIndex.top().second].top();
                colorIds[mxIndex.top().second].pop();

                int prevLast = colorIds[mxIndex.top().second].top();
                mxIndex.push({prevLast, mxIndex.top().second});

                colorIds[mxIndex.top().second].push(last);

                if (prevLast != mxIndex.top().first)
                    mxIndex.pop();
                else
                    break;
            }
        }

        if (!colorIds[color].empty()) {
            mxIndex.push({colorIds[color].top(), color});
        }

        int n = cum.size();
        int cnt = n+1;
        cum.push_back(weight);
        if (n > 0) {
            cum[n] += cum[n-1];
        }

        mx[node] = {cum[n], cnt};
        if (!mxIndex.empty()) {
            int prev = mxIndex.top().first + 1;
            mx[node].first -= cum[prev];
            mx[node].second -= prev;
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
        priority_queue<pp> mxIndex;
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

int main() {
    vector<vector<int>> edges = {{2,5,6},{0,3,9},{4,1,5},{1,0,5},{5,0,4}};
    vector<int> nums = {2,3,2,5,1,4};
    auto x = Solution().longestSpecialPath(edges, nums);
    for (int i:x) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}