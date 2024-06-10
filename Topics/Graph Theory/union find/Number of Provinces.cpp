#include <bits/stdc++.h>
//https://leetcode.com/problems/number-of-provinces/submissions/963625952/

using namespace std;

class Dsu {
    public:
        int parent[200];
        int rank[200];
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

        int count() {
            map<int, int> occ;
            for (int i=0 ; i<n ; i++) {
                cout<<parent[i]<<endl;
                occ[find(i)]++;
            }

            return occ.size();
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        Dsu dsu = Dsu(n);
        for (int i=0 ; i<n ; i++)
        {
            for (int j=0 ; j<n ; j++)
            {
                if (i==j || !v[i][j])
                    continue;

                dsu.unionn(i, j);
            }
        }

        return dsu.count();
    }
};