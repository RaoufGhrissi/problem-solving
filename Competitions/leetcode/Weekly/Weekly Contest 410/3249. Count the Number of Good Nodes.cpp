#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int ans = 0;

    int get(int root, vector<vector<int>> &graph, int parent) {
        int res = 1;

        int prev = -1;
        bool ok = 1;

        for (int &child: graph[root]) {
            if (child != parent) { // hedhi tekhdem ken f tree khater mafamech cycle
                int l = get(child, graph, root); // size tree eli sghiri root mte3ha

                if (prev==-1) // hedha awel sghir
                    prev = l; // hot size = size mta3 awel sghir
                else if (ok && prev != l) // mahouch awel sghir donc nhot prev = size mte3ou bech n9arnou beha
                    ok = 0; // mahich mrigla

                res += l;
            }
        }

        if (ok)
            ans++; // 3andi good tree jdida

        return res;
    }

    int countGoodNodes(vector<vector<int>>& e) {
        int n = e.size() + 1;

        vector<vector<int>> graph(n);

        for (auto &ee:e) {
            graph[ee[0]].push_back(ee[1]);
            graph[ee[1]].push_back(ee[0]);
        }

        get(0, graph, -1);
        return ans;
    }
};