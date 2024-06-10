#include <bits/stdc++.h>

using namespace std;

class Dsu {
    public:
        int const static N = 1e5;
        int parent[N];
        int rank[N];
        int andd[N];
        int n;

        Dsu(int k) {
            n = k;
            for (int i=0 ; i<n ; i++) {
                parent[i] = i;
                rank[i] = 1;
                andd[i] = -1;
            }
        }

        int find(int i) {
            if (parent[i] != i)
                return parent[i] = find(parent[i]);

            return parent[i] = i;
        }

        void unionn(int a, int b, int w) {
            int p1 = find(a);
            int p2 = find(b);

            if (rank[p1] < rank[p2])
                swap(p1, p2);

            parent[p2] = p1;
            if (andd[p1] == -1) andd[p1] = w;
            if (andd[p2] == -1) andd[p2] = w;
            andd[p1] = andd[p1]&andd[p2]&w;
            rank[p1] += rank[p2];
            rank[p2] = 0;
        }

        int get(int a, int b) {
            if (find(a) != find(b)) return -1;
            return andd[find(a)]; 
        }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        Dsu dsu = Dsu(n);
        for (auto &e:edges) {
            dsu.unionn(e[0], e[1], e[2]);
        }

        vector<int> ans;
        for (auto &q:query) {
            ans.push_back(dsu.get(q[0], q[1]));
        }

        return ans;
    }
};