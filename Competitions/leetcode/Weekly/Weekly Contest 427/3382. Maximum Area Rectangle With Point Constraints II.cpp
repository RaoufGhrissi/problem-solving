#include <bits/stdc++.h>
#define ll long long
#define pp pair<int,int>

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

        ll get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return 1e9;

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
    ll maxRectangleArea(vector<int>& xx, vector<int>& yy) {
        map<int, vector<int>> lines;
        unordered_map<int, vector<int>> cols;

        Compressor x = Compressor(xx);
        int n = x.last;

        vector<ll> a(n, -1);
        SegTree seg = SegTree(a);
        
        for (int i=0 ; i<xx.size() ; i++) {
            lines[yy[i]].push_back(xx[i]);
            cols[xx[i]].push_back(yy[i]);
        }

        unordered_map<int, int> idPerCol;

        for (auto &a:cols) {
            sort(a.second.begin(), a.second.end());
            seg.update(x.match[a.first], a.second[0], 0, 0, n-1);
            idPerCol[a.first] = 0;
        }

        ll ans = -1;
        for (auto &a:lines) {
            sort(a.second.begin(), a.second.end());

            for (int i=0 ; i<a.second.size() ; i++) {
                int x1 = a.second[i];
                if (idPerCol[x1] == cols[x1].size()) continue;
                seg.update(x.match[x1], idPerCol[x1] + 1 < cols[x1].size() ? cols[x1][idPerCol[x1] + 1] : 1e9, 0, 0, n-1);
                idPerCol[x1]++;
            }

            if (a.second.size() < 2) continue;

            for (int i=0 ; i<a.second.size()-1 ; i++) {
                int x1 = a.second[i];
                int x2 = a.second[i+1];
                
                int near1 = seg.get(x.match[x1], x.match[x1], 0, 0, n-1); 
                int near2 = seg.get(x.match[x2], x.match[x2], 0, 0, n-1);

                if (near1 == (int)1e9 || near2 != near1)
                    continue;

                int mid = seg.get(x.match[x1] + 1, x.match[x2] - 1, 0, 0, n-1);
                if (mid <= near1) continue;

                ans = max(ans, (x2 - x1) * 1ll * (near1 - a.first));
            }
        }
        
        return ans;
    }
};