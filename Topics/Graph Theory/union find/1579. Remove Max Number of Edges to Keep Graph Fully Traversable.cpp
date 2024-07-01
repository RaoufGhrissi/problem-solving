#include <bits/stdc++.h>

using namespace std;

class Dsu {
    public:
        int const static N = 1e5;
        int parent[N];
        int rank[N];
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

        bool areConnected(int a, int b) {
            return find(a) == find(b);
        }

        bool isFullyConnected() {
            int ref = find(0);
            for (int i=1 ; i<n ; i++) {
                if (find(i) != ref)
                    return 0;
            }

            return 1;
        }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& v) {
        Dsu alice(n), bob(n);
        sort(v.begin(), v.end(), greater<vector<int>>());

        int ans = 0;
        for (auto &e:v) {
            int a = e[1], b = e[2], t = e[0];
            a--;
            b--;
            if (t == 3) {
                if (alice.areConnected(a, b) && bob.areConnected(a, b))
                    continue;

                alice.unionn(a, b);
                bob.unionn(a, b);
                ans++;
            } else if (t == 1 && !alice.areConnected(a, b)) {
                alice.unionn(a, b);
                ans++;
            } else if (t == 2 && !bob.areConnected(a, b)) {
                bob.unionn(a, b);
                ans++;
            }
        }

        return alice.isFullyConnected() && bob.isFullyConnected() ? v.size() - ans : -1;
    }
};

int main() {
    vector<vector<int>> v = {{3,2,3},{1,1,2},{2,3,4}};
    cout<<Solution().maxNumEdgesToRemove(4, v);
}