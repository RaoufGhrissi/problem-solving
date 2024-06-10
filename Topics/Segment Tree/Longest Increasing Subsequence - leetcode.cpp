#include <bits/stdc++.h>

using namespace std;

class Compressor {
    public:
        set<int> v;
        map<int, int> match;
        map<int, int> inversedMatch;

    Compressor(vector<int> a) {
        for (auto &e:a)
            v.insert(e);
        
        build();
    }

    void build() {
        int i = 0;
        for (auto &a: v) {
            match[a] = i;
            inversedMatch[i] = a;
            i++;
        }
    }
};



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

        void update(int pos, int val, int id, int ns, int ne)
        {
            if (pos>ne || pos<ns)
                return;

            if (ns==ne)
            {                
                tree[id]=val;
                return ;
            }

            int l=2*id+1;
            int r=l+1;
            int mid=(ns+ne)/2;

            update(pos,val,l,ns,mid);
            update(pos,val,r,mid+1,ne);

            tree[id]=mergee(tree[l],tree[r]);
        }
};

int solve(vector<int> v) {
    int k = v.size();
    Compressor comp = Compressor(v);
    int n = comp.match.size();
    vector<int> a(n, 0);
    SegTree segTree = SegTree(a);

    vector<int> val(n, 0);
    int ans = 0;
    for (int i=0 ; i<k ; i++) {
        int m = comp.match[v[i]];
        int mx = !m ? 0 : segTree.get(0, m-1, 0, 0, n-1);

        if ((mx+1) > val[m]) {
            segTree.update(m, mx+1, 0, 0, n-1);
            val[m] = mx+1;
        }
    }


    return segTree.get(0, n-1, 0, 0, n-1);
}


// 0 1 0 3 2 3
class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        return solve(v);
    }
};