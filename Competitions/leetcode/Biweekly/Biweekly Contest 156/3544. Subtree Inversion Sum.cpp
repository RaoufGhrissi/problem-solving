#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    int kk;
    vector<vector<int>> graph;
    ll dp[5000][51][2];

    ll rec(int node, int k, int inv, vector<int>& nums, int parent = -1) {
        ll &ans = dp[node][k][inv];

        if (ans != 1e5)
            return ans;

        k--;

        // don't invert
        ans = inv&1 ? -nums[node] : nums[node];
        for (int &child:graph[node]) {
            if (child != parent) {
                ans += rec(child, max(0, k), inv, nums, node);
            }
        }

        // invert if possible
        if (k>0) // not  possible
            return ans;
        
        inv = inv ? 0 : 1;  
        ll res = inv&1 ? -nums[node] : nums[node];
        for (int &child:graph[node]) {
            if (child != parent) {
                res += rec(child, kk, inv, nums, node);
            }
        }

        return ans = max(ans, res);
    }

    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        int n = edges.size() + 1;
        graph.resize(n);
        kk = k;

        for (auto &e:edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

       for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<=k ; j++) {
                dp[i][j][0] = 1e5;
                dp[i][j][1] = 1e5;
            }
       }

        return rec(0, 0, 0, nums);
    }
};

int main() {
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4}};
    vector<int> v = {-1,3,-2,4,-5};
    cout<<Solution().subtreeInversionSum(edges, v, 2);
}