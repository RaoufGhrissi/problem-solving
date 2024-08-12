#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<ll, ll>

struct node {
    ll sum;
    ll lazy;
    bool update;
    
    node() {
        sum=0;
        lazy=0;
        update=false;
    }

    node(ll _sum, ll _lazy, bool _update)
    {
        sum = _sum;
        lazy = _lazy;
        update = _update;
    }
};

class LazySegTree {
    public:
        vector<node> tree;

        LazySegTree(int n) {
            tree.resize(4*n);
        }

        node mergee(node &l, node &r) {
            return node(l.sum + r.sum, 0, false);
        }

        void unlazy(int id, int ns, int ne) {
            if (!tree[id].update)
                return ;

            if (ns != ne) //having children
            {
                int left = 2*id + 1;
                int right = left + 1;
                int mid = (ns+ne)/2;

                tree[left].update = true;
                tree[right].update = true;

                tree[left].lazy = tree[id].lazy;
                tree[right].lazy = tree[id].lazy;

                tree[left].sum = (mid-ns+1)*tree[id].lazy;
                tree[right].sum = (ne-mid)*tree[id].lazy;
            }

            tree[id].lazy = 0;
            tree[id].update = false;
        }

        void update(int qs, int qe, ll val, int id, int ns, int ne) {
            unlazy(id, ns, ne);

            if (qs>ne || qe<ns)
                return ;

            if (qs<=ns && ne<=qe)
            {
                tree[id].sum = val*(ne-ns+1);
                tree[id].lazy = val;
                tree[id].update = true;

                return ;
            }

            int left = 2*id + 1;
            int right = left + 1;
            int mid = (ns+ne)/2;

            update(qs, qe, val, left, ns, mid);
            update(qs, qe, val, right, mid+1, ne);

            tree[id] = mergee(tree[left], tree[right]);
        }

        node get(int qs, int qe, int id, int ns, int ne) {
            unlazy(id, ns, ne);

            if (qe<ns || qs>ne)
                return node(0, 0, false);

            if (qs<=ns && ne<=qe)
                return tree[id];

            int left = 2*id + 1;
            int right = left + 1;
            int mid = (ns+ne)/2;

            node q1 = get(qs, qe, left, ns, mid);
            node q2 = get(qs, qe, right, mid+1, ne);

            return mergee(q1, q2);
        }
};

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

class Solution {
public:
    long long numberOfSubarrays(vector<int>& v) {
        Compressor comp = Compressor(v);
        int n = comp.last;

        LazySegTree seg = LazySegTree(n);
        ll ans = 0;

        for (auto &a:v) {
            int m = comp.match[a];
            int val = seg.get(m, m, 0, 0, n-1).sum;
            seg.update(m, m, val+1, 0, 0, n-1);
            ans += val+1;

            if (m)
                seg.update(0, m-1, 0, 0, 0, n-1);
        }

        return ans;
    }
};