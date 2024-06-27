#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

//dp, seg tree with compression, not direct application for seg tree
//dp opitmized, 
// for (int i=l ; i<r ; i++) ans = max(ans, rec(i, k)) => najem naamel segtree o(n) => lgo(n) / TLE => accepted

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
        last = 1;
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
    static const int N = 5000;
    int dp[N][51];

    int maximumLength(vector<int>& v, int k) {
        int ans = 0;
        int n = v.size();

        Compressor comp = Compressor(v);
        vector<int> s(comp.last, 0);

        SegTree seg[k+1];

        for (int i=0 ; i<=k ; i++)
            seg[i] = SegTree(s);
        
        for (int i=0 ; i<n ; i++) {
            int index = comp.match[v[i]];
            for (int kk=k ; kk>-1 ; kk--) {
                dp[i][kk] = 1;
                dp[i][kk] = max(dp[i][kk], 1 + seg[kk].get(index, index, 0, 0, comp.last-1));
                if (kk>0)
                    dp[i][kk] = max(dp[i][kk], 1+max(seg[kk-1].get(0, index-1, 0, 0, comp.last-1), seg[kk-1].get(index+1, comp.last-1, 0, 0, comp.last-1)));

                seg[kk].update(index, dp[i][kk], 0, 0, comp.last-1);
                ans = max(ans, dp[i][kk]);
            }
        }

        return ans;
    }
};