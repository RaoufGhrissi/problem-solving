#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define pp pair<char,int>

#include <bits/stdc++.h>

using namespace std;

#define inf 1e6

#define ll long long

struct node {
    int lc;
    int rc;
    int lrc;
    int no;

    node() {
        lc = -inf;
        rc = -inf;
        lrc = -inf;
        no = -inf;
    }

    node(int l, int r, int lr, int _no) {
        lc = l;
        rc = r;
        lrc = lr;
        no = _no;
    }
};


class SegTree {
    public:
        vector<int> v;
        vector<node> tree;
        int n;

        SegTree(vector<int> a){
            v = a;
            n = v.size();
            tree.resize(4*n);
            build(0, 0, n-1);
        }

        node mergee(node &l, node &r) {
            int lc = max({
                l.lc + max(r.lc, r.no),
                l.lrc + r.no
            });

            int rc = max({
                r.rc + max(l.rc, l.no),
                r.lrc + l.no,
            });

            int no = max({
                r.no + max(l.no, l.rc),
                r.lc + l.no,
            });

            int lrc = max({
                r.rc + max(l.lc, l.lrc),
                r.lrc + l.lc,
            });

            return node(lc, rc, lrc, no);
        }

        void build(int i, int is, int ie) {
        	if (is == ie) {
        		tree[i] = node(0, 0, v[is], 0);
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
                return node(-inf, -inf, -inf, -inf);

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
        		tree[i] = node(0, 0, val, 0);
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
    int mod = 1e9 + 7;
    int maximumSumSubsequence(vector<int>& v, vector<vector<int>>& q) {
        ll ans = 0;
        
        int n = v.size();
        
        SegTree seg = SegTree(v);
        
        for (auto &qq:q) {
            int pos = qq[0];
            int x = qq[1];

            seg.update(pos, x, 0, 0, n-1);
            node nn = seg.get(0, n-1, 0, 0, n-1);
            ans += max({nn.lc, nn.rc, nn.lrc, nn.no});
            ans %= mod;
        }

        return ans;
    }
};