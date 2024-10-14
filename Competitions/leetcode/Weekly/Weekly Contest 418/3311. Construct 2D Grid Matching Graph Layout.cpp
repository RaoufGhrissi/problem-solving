#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

using namespace std;

class Solution {
public:
    vector<bool> vis;
    void backtrack(vector<int> &res, vector<vector<int>> &ans, vector<vector<int>> &graph, int &n) {
        int l = res.size();
        int sm = res[l-1];
        if (l>1 && !(n%l) && graph[sm].size() == 2) {
            ans.push_back(res);
            return;
        }

        for (int &child:graph[sm]) {
            if (!vis[child] && graph[child].size() <= 3) {
                vis[child] = 1;
                res.push_back(child);
                backtrack(res, ans, graph, n);
                if (!ans.empty()) return;
                vis[child] = 0;
                res.pop_back();
            }
        }
    }
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for (auto &ee:edges) {
            int x = ee[0];
            int y = ee[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<vector<int>> sz(5);

        for (int i=0 ; i<n ; i++) {
            sz[graph[i].size()].push_back(i);
        }

        vis.clear();
        for (int i=0 ; i<n ; i++) vis.push_back(0);

        if (!sz[1].empty()) {
            vector<vector<int>> ans(1, vector<int>(n));

            int sm = sz[1][0];
            ans[0][0] = sm;
            vis[sm] = 1;

            for (int col=1 ; col<n ; col++) { 
                for (int &child:graph[ans[0][col-1]]) {
                    if (!vis[child]) {
                        vis[child] = 1;
                        ans[0][col] = child;
                        break;
                    }
                }
            }

            return ans;
        }
    
        vector<vector<int>> ans;
        int sm = sz[2][0];
        vector<int> res = {sm};
        vis[sm] = 1;
        backtrack(res, ans, graph, n);

        for (int line=1 ; line<n/ans[0].size() ; line++) {
            ans.push_back({});
            for (int col=0 ; col<ans[0].size() ; col++) {
                for (int &child:graph[ans[line-1][col]]) {
                    if (!vis[child]) {
                        ans[line].push_back(child);
                        vis[child] = 1;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};



int main() {
    vector<vector<int>> v = {{0,1},{0,4},{0,5},{1,7},{2,3},{2,4},{2,5},{3,6},{4,6},{4,7},{6,8},{7,8}}; //{{0,1},{0,2},{1,3},{2,3}};
    int k = 9; // 4
    auto a = Solution().constructGridLayout(k, v);
    int b = 5;
}