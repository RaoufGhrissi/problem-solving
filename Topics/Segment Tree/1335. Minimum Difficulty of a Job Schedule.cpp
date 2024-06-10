// dp
#include <bits/stdc++.h>

using namespace std;

class SegTree {
    public:
        vector<int> v;
        vector<int> tree;
        int n;

        SegTree(vector<int> a){
            v = a;
            n = v.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        int mergee(int l, int r) {
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

        int get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return 0;

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
    int dp[300][300][11];
    int rec(int i, int prev, int d, int &n, SegTree &segTree) {
        if (i == n) {
            return d ? 1e9 : 0;
        }

        if (!d) {
            return 1e9;
        }

        if (dp[i][prev][d] != -1) {
            return dp[i][prev][d];
        }

        int &ans = dp[i][prev][d];
        ans = min(segTree.get(prev, i, 0, 0, n-1) + rec(i+1, i+1, d-1, n, segTree), rec(i+1, prev, d, n, segTree));

        return ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (d>n)
            return -1;

        memset(dp, -1, sizeof dp);
        SegTree segTree = SegTree(jobDifficulty);

        return rec(0, 0, d, n, segTree); 
    }
};
