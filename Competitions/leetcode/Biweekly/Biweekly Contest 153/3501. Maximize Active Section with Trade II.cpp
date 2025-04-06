#include <bits/stdc++.h>

using namespace std;

#define ll long long

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

        int get(int qs, int qe, int i, int is, int ie) {
        	if (qs <= is && qe >= ie)
        		return tree[i];

            if (qs > ie || qe < is)
                return 0;

        	int left = 2*i+1;
        	int right = left+1;
        	int mid = (is+ie)/2;
        	ll l = get(qs, qe, left, is, mid);
        	ll r = get(qs, qe, right, mid+1, ie);
        	return mergee(l, r);
        }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<vector<int>> seqs;
        vector<vector<int>> v;
        vector<int> a;
        vector<int> cum(n);

        for (int i=0 ; i<n ; i++) {
            cum[i] = s[i]-'0';
            if (i)
                cum[i] += cum[i-1];
        }

        int zerosBefore = 0;
        int ones = 0;

        int cnt = 1;
        int start = 0;
        for (int i=1 ; i<n ; i++) {
            if (s[i] == s[i-1]) {
                cnt++;
            } else {
                v.push_back({s[i-1]-'0', start, cnt});
                cnt = 1;
                start = i;
            }
        }

        v.push_back({s[n-1]-'0', start, cnt});

        int m = v.size();

        for (int i=1 ; i<m-1 ; i++) {
            if (v[i][0] && !v[i-1][0] && !v[i+1][0]) {
                seqs.push_back({v[i-1][1], v[i][1], v[i+1][1], v[i+1][1]+v[i+1][2]-1});
                a.push_back(v[i-1][2] + v[i+1][2]);
            }
        }

        vector<int> ans;

        int sz = seqs.size();

        if (a.empty()) {
            for (auto &q:queries) {
                ans.push_back(cum[n-1]);
            }

            return ans;
        }

        SegTree segTree = SegTree(a);

        for (auto &q:queries) {
            int l = q[0];
            int r = q[1];

            int s = 0;
            int e = sz-1;

            while(s<e) {
                int mid = (s+e)/2;

                if (seqs[mid][1] <= l) {
                    s = mid+1;
                } else {
                    e = mid;
                }
            }

            int left = s;

            s = 0;
            e = sz-1;

            while(s<e) {
                int mid = (s+e+1)/2;

                if (seqs[mid][2] > r) {
                    e = mid-1;
                } else {
                    s = mid;
                }
            }

            int right = s;
            int res = cum[n-1];

            if (right < left) {
                ans.push_back(res);
            } else if (right == left) {
                if (seqs[left][1] > l && seqs[left][2] <= r) {
                    ans.push_back(res + seqs[left][1] - max(l, seqs[left][0]) + min(r, seqs[left][3]) - seqs[left][2] + 1);
                } else {
                    ans.push_back(res);
                }
            } else {
                int calc = res;
                int mx = segTree.get(left, left, 0, 0, sz-1) - (max(l, seqs[left][0]) - seqs[left][0]);
                mx = max(mx, segTree.get(right, right, 0, 0, sz-1) - (seqs[right][3] - min(r,  seqs[right][3])));
                ans.push_back(calc + max(mx, segTree.get(left+1, right-1, 0, 0, sz-1)));
            }
        }

        return ans;
    }
};