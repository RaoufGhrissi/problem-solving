#include <bits/stdc++.h>
#define ll long long

using namespace std;

class Dsu {
    public:
        int parent[1002];
        int rank[1002];
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
    bool circle(ll x1, ll y1, ll x2, ll y2, ll r1, ll r2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
    }

    bool canReachCorner(int X, int Y, vector<vector<int>>& c) {
        int n = c.size();
        //n = left top
        //n+1 = right button

        Dsu dsu = Dsu(n+2);

        for (int i=0 ; i<n ; i++) {
            vector<int> cc = c[i];
            int x = cc[0];
            int y = cc[1];
            int r = cc[2];

            if (x-r <= 0 || y+r >= Y) { // top or left
                dsu.unionn(n, i);
            }

            if (x+r >= X || y-r <= 0) {
                dsu.unionn(n+1, i);
            }

            for (int j=0 ; j<i ; j++) {
                if (circle(x, y, c[j][0], c[j][1], r, c[j][2])) {
                    dsu.unionn(j, i);
                }
            }
        }

        return dsu.find(n) != dsu.find(n+1);
    }
};