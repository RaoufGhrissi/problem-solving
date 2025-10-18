#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct node {
    int r;
    int occRest[5];

    node() {
        r = -1;
        for (int i=0 ; i<5 ; i++)
            occRest[i] = 0;
    }

    node(int v, int k) {
        r = v%k;
        for (int i=0 ; i<5 ; i++)
            occRest[i] = 0;

        occRest[r]++;
    }
};

class SegTree {
    public:
        vector<int> v;
        vector<node> tree;
        int n;
        int k;

        SegTree(vector<int> a, int _k){
            v = a;
            n = v.size();
            k = _k;
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        node mergee(node l, node r) {
            if (l.r == -1) return r;
            if (r.r == -1) return l;

            node ans = node();
            ans.r = (l.r*r.r) % k;
            for (int i=0 ; i<5 ; i++)
                ans.occRest[i] = l.occRest[i];

            for (int i=0 ; i<5 ; i++) {
                int rest = (l.r * i)%k;
                ans.occRest[rest] += r.occRest[i]; 
            }

            return ans;
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = node(v[is], k);
        		return;
        	}

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	build(left, is, mid);
        	build(right, mid+1, ie);

        	tree[i] = mergee(tree[left], tree[right]);
        }

        node get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return node();

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	node l = get(qs, qe, left, is, mid);
        	node r = get(qs, qe, right, mid+1, ie);
        	return mergee(l, r);
        }

        void update(int index, int val, int i, int is, int ie) {
        	if (index < is || index > ie)
        		return;

        	if (is == ie) {
        		tree[i] = node(val, k);
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
    vector<int> resultArray(vector<int>& v, int k, vector<vector<int>>& queries) {
        SegTree seg = SegTree(v, k);
        int n = v.size();
        vector<int> ans;

        for (auto &q:queries) {
            int index = q[0];
            int value = q[1];

            int start = q[2];
            int xi = q[3];

            seg.update(index, value, 0, 0, n-1); 
            
            node qq = seg.get(start, n-1, 0, 0, n-1);
            ans.push_back(qq.occRest[xi]);
        }

        return ans;
    }
};