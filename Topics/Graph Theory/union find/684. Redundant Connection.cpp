// https://leetcode.com/problems/greatest-common-divisor-traversal/

#include <bits/stdc++.h>

using namespace std;

class Dsu {
    public:
        int parent[10000];
        int rank[10000];
        int n;

        Dsu(int k) {
            n = k;
            for (int i=0 ; i<n ; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int i) {
            if (parent[i] != i)
                return parent[i] = find(parent[i]);

            return parent[i] = i;
        }

        void unionn(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);

            if (rank[p1] < rank[p2])
                swap(p1, p2);

            parent[p2] = p1;
            rank[p1] += rank[p2];
            rank[p2] = 0;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        int n = e.size();
        Dsu dsu = Dsu(1001);

        for (int i=n-1 ; i>-1 ; i--) {
            if (dsu.find(e[i][0]) == dsu.find(e[i][1]))
                return e[i];

            dsu.unionn(e[i][0], e[i][1]);
        }

        return {-1, -1};
    }
};