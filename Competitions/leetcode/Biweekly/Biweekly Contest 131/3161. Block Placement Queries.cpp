#include <bits/stdc++.h>

using namespace std;

#define ll long long

class SegTree {
    public:
        vector<ll> v;
        vector<ll> tree;
        int n;

        SegTree(vector<ll> a){
            v = a;
            n = v.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        ll mergee(ll l, ll r) {
            return max(l, r);
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

        ll get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return -1;

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	ll l = get(qs, qe, left, is, mid);
        	ll r = get(qs, qe, right, mid+1, ie);
        	return mergee(l, r);
        }

        void update(int index, int val, int i, int is, int ie) {
        	if (index < is || index > ie)
        		return;

        	if (is == ie) {
        		tree[i] = val;
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
    vector<bool> getResults(vector<vector<int>>& q) {
        int n = 50007;
        vector<ll> v(n, 0);

        SegTree segTree = SegTree(v);

        set<int> obs;
        
        obs.insert(0);
        vector<bool> ans;
        for (auto &qq:q) {
            int x = qq[1];
            auto it = obs.lower_bound(x);
            int lb = *prev(it);
            
            if (qq[0] == 1) {
                segTree.update(x, x-lb, 0, 0, n-1);
                obs.insert(x);
                if (it != obs.end()) {
                    int index = *it;
                    segTree.update(index, index-x, 0, 0, n-1);
                }
            }
            else {
                int sz = qq[2];
                ans.push_back((segTree.get(0, lb, 0, 0, n-1) >= sz) || (x-lb >= sz));
            }
        }
        
        return ans;
    }
};