#define pp pair<int,int>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct node {
    ll val;
    ll lazy;
    bool update;
    
    node() {
        val=0;
        lazy=0;
        update=false;
    }

    node(ll _val, ll _lazy, bool _update)
    {
        val = _val;
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
            return node(l.val + r.val, 0, 0);
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

                tree[left].lazy += tree[id].lazy;
                tree[right].lazy += tree[id].lazy;

                tree[left].val += tree[id].lazy;
                tree[right].val += tree[id].lazy;
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
                tree[id].val += val;
                tree[id].lazy += val;
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

class Solution {
public:
    vector<int> flat;
    vector<int> index;
    vector<int> size;
    vector<int> dist;

    vector<unordered_map<int,int>> weight;

    vector<vector<pp>> graph;

    int dfs(int node, int parent = -1, int w = 0) {
        index[node] = flat.size();
        flat.push_back(node);
        size[node] = 1;
        dist[node] = w;

        for (auto &child:graph[node]) {
            int x = child.first;
            int wChild = child.second;

            if (x == parent) continue;
            weight[node][x] = wChild;
            size[node] += dfs(x, node, w + wChild);            
        }

        return size[node];
    }

    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        graph.resize(n);
        index.resize(n);
        size.resize(n);
        dist.resize(n);
        weight.resize(n);

        int x = 1LL;
        for (auto &e:edges) {
            int x = e[0]-1;
            int y = e[1]-1;
            int w = e[2];

            graph[x].push_back({y,w});
            graph[y].push_back({x,w});
        }

        dfs(0, -1);

        vector<int> ans;

        LazySegTree seg = LazySegTree(n);

        for (int i=0 ; i<n ; i++)
            seg.update(index[i], index[i], dist[i], 0, 0, n-1);

        for (auto &q:queries) {
            int type = q[0];

            if (type == 1) {
                int x = q[1]-1;
                int y = q[2]-1;
                int w = q[3];

                // y ancestor of x 
                if (dist[y] > dist[x])
                    swap(x, y);

                int oldW = weight[y][x];
                weight[y][x] = w;
                seg.update(index[x], index[x]+size[x]-1, w - oldW, 0, 0, n-1);
            } else {
                int x = q[1]-1;
                ans.push_back(seg.get(index[x], index[x], 0, 0, n-1).val);
            }
        }

        return ans;
    }
};
