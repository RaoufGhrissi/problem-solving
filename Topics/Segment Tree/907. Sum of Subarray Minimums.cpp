//https://leetcode.com/problems/sum-of-subarray-minimums/?envType=daily-question&envId=2024-01-20

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;

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
            if (l == -1) return r;
            if (r == -1) return l;

            if (v[l] < v[r])
                return l;

            return r;
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = ie;
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
                return -1;

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
    int solve(int i, int j, SegTree &segTree, vector<int> &v, int &n) {
        if (i>j) return 0;

        int index = segTree.get(i, j, 0, 0, n-1);

        ll r = j-index;
        ll l = index-i;
        ll ans = (v[index] * 1ll * (1ll + r + l + r*l)) + solve(i, index-1, segTree, v, n)%mod + solve(index+1, j, segTree, v, n)%mod;
        ans %= mod;

        return ans;
    }

    int sumSubarrayMins(vector<int>& v) {
        int n = v.size();
        SegTree segTree = SegTree(v);
        return solve(0, n-1, segTree, v, n);
    }
};

int main() {
    vector<int> v = {3,1,2,4};
    cout<<Solution().sumSubarrayMins(v);
    return 0;
}
