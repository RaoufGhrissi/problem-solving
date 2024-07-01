#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findMid(vector<vector<int>> &tree, int &n) {
        if (n == 1) {
            return {0};
        }
        vector<int> in(n);
        vector<bool> vis(n, 0);
        queue<int> q;

        for (int i=0 ; i<n ; i++) {
            in[i] = tree[i].size();
            if (in[i] == 1)
                q.push(i);
        }
        
        int tot = n;
        while(tot > 2) {
            vector<int> next;
            while(!q.empty()) {
                int f = q.front();
                vis[f] = 1;
                next.push_back(f);
                q.pop();
                tot--;
            }

            for (auto &f:next) {
                for (auto &child:tree[f]) {
                    in[child]--;
                    if (in[child] == 1)
                        q.push(child);
                }
            }
        }

        vector<int> ans;
        for (int i=0 ; i<n ; i++) {
            if (!vis[i]) ans.push_back(i);
        }

        return ans;
    }

    int getMxDist(int p, vector<vector<int>> &tree, vector<bool> &vis) {
        vis[p] = 1;
        int ans = 0;

        for (auto &child:tree[p]) {
            if (!vis[child]) {
                ans = max(ans, 1 + getMxDist(child, tree, vis));
            }
        }

        return ans;
    }

    vector<int> getDist(vector<vector<int>> &tree, int &m, int &n) {
        vector<bool> vis(n, 0);
        vis[m] = 1;

        vector<int> ans;

        for (int &child:tree[m])
            ans.push_back(1 + getMxDist(child, tree, vis));

        sort(ans.begin(), ans.end());
        if (ans.empty())
            return {0};

        return ans;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int n = e1.size() + 1;
        int m = e2.size() + 1;

        vector<vector<int>> tree1(n), tree2(m);

        for (auto &e:e1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }

        for (auto &e:e2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        vector<int> m1 = findMid(tree1, n);
        vector<int> m2 = findMid(tree2, m);

        int ans = 1e9;

        for (auto &mm1:m1) {
            for (auto &mm2:m2) {
                vector<int> d1 = getDist(tree1, mm1, n);
                vector<int> d2 = getDist(tree2, mm2, m);

                int nd1 = d1.size();
                int nd2 = d2.size();

                int mx1 = d1[nd1 - 1];
                int mx2 = d2[nd2 - 1];
                
                int res = mx1 + mx2 + 1;

                if (nd1 > 1) {
                    res = max(res, mx1 + d1[nd1 - 2]);
                }

                if (nd2 > 1) {
                    res = max(res, mx2 + d2[nd2 - 2]);
                }

                ans = min(ans,  res);
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> v1 = {}; //{{1,3},{2,4},{0,2},{1,7},{6,1},{0,6},{5,0},{5,8}};
    vector<vector<int>> v2 = {}; //{{2,0},{2,1},{2,3}};
    auto a = Solution().minimumDiameterAfterMerge(v1, v2);
    cout<<a<<endl;
}