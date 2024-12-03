#include<bits/stdc++.h>

using namespace std;

class EulerianDirectedGraph {
    public:
        map<int, vector<int>> graph;
        map<int, int> in, out;
        vector<int> path;
        int n;

        EulerianDirectedGraph(map<int, vector<int>> &g) {
            graph = g;
            n = g.size();
            init();
        }

        void init() {
            for (auto &gg:graph) {
                for (int &child:gg.second) {
                    out[gg.first]++;
                    in[child]++;
                }
            }
        }

        int getStart() {
            int res;
            for (auto &a:graph) {
                res = a.first;
                if (in[res] < out[res]) return res;
            }

            return res;
        }

        void dfs(int i) {
            while(out[i] > 0) {
                out[i]--;
                dfs(graph[i][out[i]]);
            }

            path.push_back(i);
        }
};

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& p) {
        map<int, vector<int>> graph;

        for (auto &pp:p) {
            graph[pp[0]].push_back(pp[1]);
        }

        EulerianDirectedGraph euler = EulerianDirectedGraph(graph);

        euler.dfs(euler.getStart());

        vector<vector<int>> ans;

        reverse(euler.path.begin(), euler.path.end());

        int n = euler.path.size();
        for (int i=1 ; i<n ; i++) {
            ans.push_back({euler.path[i-1], euler.path[i]});
        }

        return ans;
    }
};