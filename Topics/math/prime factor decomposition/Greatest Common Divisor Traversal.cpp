//https://leetcode.com/problems/greatest-common-divisor-traversal/
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

        int count() {
            map<int, int> occ;
            for (int i=0 ; i<n ; i++) {
                occ[find(i)]++;
            }

            return occ.size();
        }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> temp;
        set<int> st;
        int m = 0;
        map<int,int> compressor;
        int onesCnt = 0;
        for (auto &x:nums) {
            onesCnt += x == 1;

            temp.clear();
            for (int i=2 ; i<=sqrt(x) ; i++) {
                bool added = 0;
                while (x > 1 && !(x%i)) {
                    x /= i;
                    if (!added) {
                        temp.push_back(i);
                        st.insert(i);
                        added = 1;
                    }
                }
            }

            if (x > 1) {
                temp.push_back(x);
                st.insert(x);
            }

            v.push_back(temp);
        }

        if (onesCnt > 0) {
            if (onesCnt == 1 && nums.size() == 1)
                return 1;

            return 0;
        }

        for (auto &a:st) {
            compressor[a] = m++;
        }

        Dsu dsu = Dsu(m);

        for (auto &a:v) {
            int n = a.size();
            for (int i=1 ; i<n ; i++) {
                dsu.unionn(compressor[a[i]], compressor[a[i-1]]);
            }
        }

        return dsu.count() == 1;
    }
};
