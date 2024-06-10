#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<int, int>
#define Raouf ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)

struct node {
    ll sum;
    ll lazy;
    bool update;
    node(){
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

        node query(int qs, int qe, int id, int ns, int ne) {
            unlazy(id, ns, ne);

            if (qe<ns || qs>ne)
                return node(0, 0, false);

            if (qs<=ns && ne<=qe)
                return tree[id];

            int left = 2*id + 1;
            int right = left + 1;
            int mid = (ns+ne)/2;

            node q1 = query(qs, qe, left, ns, mid);
            node q2 = query(qs, qe, right, mid+1, ne);

            return mergee(q1, q2);
        }
};

class RangeModule {
public:
    set<int> points;
    vector<vector<int>> ranges;

    RangeModule() {

    }

    void add(int l, int r, int val) {
        points.insert(l);
        points.insert(r);
        points.insert(r-1);

        ranges.push_back({l, r-1, val});
    }
    
    void addRange(int l, int r) {
        add(l, r, 1);
    }
    
    bool queryRange(int l, int r) {
        int n = 0;
        map<int, int> matched;
        points.insert(l);
        points.insert(r);
        points.insert(r-1);
        for (auto &point:points) {
            matched[point] = n++;
        }

        LazySegTree seg = LazySegTree(n);
        
        for (auto &range: ranges) {
            int s = matched[range[0]];
            int e = matched[range[1]];
            seg.update(s, e, range[2], 0, 0, n-1);
        }

        int ml = matched[l];
        int mr = matched[r-1];

        int a = seg.query(ml, mr, 0, 0, n-1).sum;
        return a == mr-ml+1;
    }
    
    void removeRange(int l, int r) {
        add(l, r, 0);
    }
};


int main() {
    RangeModule* obj = new RangeModule();
    obj->addRange(10, 180);
    obj->addRange(150, 200);
    obj->addRange(250, 500);
    bool param_2 = obj->queryRange(180, 300);

    return 0;
}