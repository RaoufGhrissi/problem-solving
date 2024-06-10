//https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/description/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

class Solution {
public:
    ll dfs(int i, int p, vector<vector<int>>& graph, vector<int>& v) {
        ll all = 0;
        for (auto &child:graph[i]) { 
            if (child!=p)
                all += dfs(child, i, graph, v);
        }

        return all ? min(v[i]*1ll, all) : v[i]*1ll;
    }

    ll maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> graph(n);

        for (auto &e:edges) {
            int x = e[0];
            int y = e[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        ll sm = accumulate(v.begin(), v.end(), 0ll);

        return sm-dfs(0, -1, graph, v);
    }
};

int main() {
    vector<vector<int>> e = {{0,1},{0,2}};//,{0,3},{2,4},{4,5}};
    vector<int> v = {1000000000,1000000000,1000000000};// {5,2,5,2,1,1};
    cout<<Solution().maximumScoreAfterOperations(e, v);
    return 0;
}