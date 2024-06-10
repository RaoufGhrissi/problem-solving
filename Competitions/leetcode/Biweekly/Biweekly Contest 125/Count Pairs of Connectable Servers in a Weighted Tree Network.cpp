#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

#include <bits/stdc++.h>

using namespace std;

#define pp pair<int,int>

class Solution {
public:
    int dfs(int node, int parent, int dist, vector<vector<pp>> &graph, int &s) {
        int ans = !(dist%s);
        for (auto &child:graph[node]) {
            int x = child.first;
            int w = child.second;
            if (x == parent)
                continue;
            
            ans += dfs(x, node, dist + w, graph, s);
        }
        
        return ans;
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int s) {
        int n = edges.size() + 1;
        vector<vector<pp>> graph(n);
        
        for (auto &a:edges) {
            int x = a[0];
            int y = a[1];
            int w = a[2];
            graph[x].push_back({y, w});
            graph[y].push_back({x, w});
        }
        
        vector<int> ans(n, 0);
        vector<int> cnt;
        
        for (int i=0 ; i<n ; i++) {
            if (graph[i].size() == 1)
                continue;
            
            cnt.clear();
            for (auto &child:graph[i]) {
                int x = child.first;
                int w = child.second;
                
                cnt.push_back(dfs(x, i, w, graph, s));
            }
            
            int k = cnt.size();
            for (int j=0 ; j<k ; j++) {
                for (int c=j+1 ; c<k ; c++) {
                    ans[i] += cnt[j]*cnt[c];
                }
            }
        }
        
        return ans;
        
    }
};