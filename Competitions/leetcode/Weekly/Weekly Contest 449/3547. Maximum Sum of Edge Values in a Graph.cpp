#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> val(n, -1);

        for (auto &e:edges) {
            int x = e[0];
            int y = e[1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        queue<int> q;
        for (int i=0 ; i<n ; i++) {
            if (graph[i].size() == 1) {
                q.push(i);
            }
        }

        if (q.empty()) {
            q.push(0);
        }

        int v = 1;

        while(!q.empty()) {
            int t = q.front();
            q.pop();

            if (val[t] != -1) continue;

            val[t] = v++;

            for (int &child:graph[t]) {
                if (val[child] == -1) {
                    q.push(child);
                }
            }
        }

        ll ans = 0;

        for (auto &e:edges) {
            int x = e[0];
            int y = e[1];

            ans += val[x]*1ll*val[y];
        }


        return ans; 
    }
};