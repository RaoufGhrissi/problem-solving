#include <bits/stdc++.h>
#define inf 2*1e9
using namespace std;

class Compressor {
    public:
        set<int> v;
        map<int, int> match;
        map<int, int> inversedMatch;
        int last;

    Compressor(vector<int> a) {
        for (auto &e:a)
            v.insert(e);
        
        build();
    }

    void build() {
        last = 0;
        for (auto &a: v) {
            match[a] = last;
            inversedMatch[last] = a;
            last++;
        }
    }
};

class SegTree {
    public:
        vector<int> v;
        vector<int> tree;
        int n;

        SegTree() {}

        SegTree(vector<int> a){
            v = a;
            n = v.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        int mergee(int l, int r) {
            return min(l, r);
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = v[ie];
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	build(left, is, mid);
        	build(right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }

        int get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return inf;

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	int l = get(qs, qe, left, is, mid);
        	int r = get(qs, qe, right, mid+1, ie);
        	return mergee(l, r);
        }

        void update(int index, int val, int i, int is, int ie) {
        	if (index < is || index > ie)
        		return;

        	if (is == ie) {
        		tree[i] = max(val, tree[i]);
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	update(index, val, left, is, mid);
        	update(index, val, right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& f, vector<int>& b) {
        vector<int> v(f.begin(), f.end());
        for (int &x:b)
            v.push_back(x);
        
        Compressor comp = Compressor(v);
        int n = comp.last;
        vector<int> a(n, inf);
        vector<vector<int>> ids(n);
        vector<int> currId(n, 0);

        for (int i=0 ; i<b.size() ; i++) {
            ids[comp.match[b[i]]].push_back(i);
            if (ids[comp.match[b[i]]].size() == 1)
                a[comp.match[b[i]]] = i;
        }

        SegTree seg = SegTree(a);
        
        int ans = 0;
        for (int i=0 ; i<f.size() ; i++) {
            int id = seg.get(comp.match[f[i]], n-1, 0, 0, n-1);
            if (id == inf)
                ans++;
            else {
                int m = comp.match[b[id]];
                seg.update(m, (currId[m] < (ids[m].size() - 1)) ? ids[m][++currId[m]] : inf, 0, 0, n-1);

            }
        }
        
        return ans;
    }
};
