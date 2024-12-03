#include<bits/stdc++.h>

using namespace std;

class EulerianDirectedGraph {
    public:
        map<string, vector<string>> graph;
        map<string, int> in, out;
        vector<string> path;
        int n;

        EulerianDirectedGraph(map<string, vector<string>> &g) {
            graph = g;
            n = g.size();
            init();
        }

        void init() {
            for (auto &gg:graph) {
                for (string &child:gg.second) {
                    out[gg.first]++;
                    in[child]++;
                }
            }
        }

        string getStart() {
            string res;
            for (auto &a:graph) {
                res = a.first;
                if (in[res] < out[res]) return res;
            }

            return res;
        }

        void dfs(string i) {
            while(out[i] > 0) {
                out[i]--;
                dfs(graph[i][out[i]]);
            }

            path.push_back(i);
        }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& v) {
        vector<string> ans;
        map<string, vector<string>> graph;

        for (auto &a:v) {
            graph[a[0]].push_back(a[1]);
        }

        for (auto &a:graph) {
            sort(a.second.begin(), a.second.end(), greater<string>());
        }

        EulerianDirectedGraph euler = EulerianDirectedGraph(graph);
        euler.dfs("JFK");

        reverse(euler.path.begin(), euler.path.end());

        return euler.path;
    }
};