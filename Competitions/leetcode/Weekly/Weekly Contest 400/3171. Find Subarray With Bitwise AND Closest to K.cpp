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

        int mergee(int l, int r) {
            return l&r;
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
};

class Solution {
public:
    int minimumDifference(vector<int>& v, int k) {
        SegTree seg = SegTree(v);

        int n = v.size();
        int ans = 1e9;

        for (int i=0 ; i<n ; i++) {
            int s = i;
            int e = n-1;

            while(s<e) {
                int mid = (s+e+1)/2;

                int x = seg.get(i, mid, 0, 0, n-1);

                if (x >= k) {
                    s = mid;
                } else {
                    e = mid-1;
                }
            }

            int x = seg.get(i, s, 0, 0, n-1);
            ans = min(ans, abs(x-k));
            if (x>k && s<n-1) {
                ans = min(ans, k - seg.get(i, s+1, 0, 0, n-1));
            }
        }



        return ans;
    }
};

int main() {
    vector<int> v = {1, 2, 4, 5};
    cout<<Solution().minimumDifference(v, 3);
    return 0;
}