#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pp pair<ll,ll>
#define newL cout<<endl
#define ll_max 1e18
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))

using namespace std;


class BinaryLifting {
    public:
        vector<vector<int>> up;
        vector<int> depth;
        vector<int> weight;
        vector<int> directParent;
        vector<vector<pp>> graph;
        int log;

        BinaryLifting(int n) {
            graph.clear();
            graph.resize(n);
            
            log = log2(n);
            log++;
            
            up.clear();
            up.resize(n, vector<int>(log));
            
            depth.clear();
            depth.resize(n);
            depth[0] = 0;

            weight.clear();
            weight.resize(n);
            weight[0] = 0;

            directParent.clear();
            directParent.resize(n);
            directParent[0] = -1;
        }

        void add(int a, int b, int w) {
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }

        void dfs(int node, int parent = -1)
        {
            if (parent != -1)
            {
                depth[node] = depth[parent]+1;
                up[node][0] = parent;
            }

            for (int i=1 ; i<log ; i++)
                up[node][i] = up[up[node][i-1]][i-1];

            for (auto child:graph[node])
            {
                int id = child.first;
                ll w = child.second;
                if (id == parent) continue;

                weight[id] = weight[node] + w;
                directParent[id] = node;
                
                dfs(id, node);
            }
        }
        
        int kthanc(int node, int k)
        {
            for (int i=log-1 ; i>-1 ; i--)
            {
                if (k&(1<<i))
                    node=up[node][i];
            }

            return node;
        }

        int lca(int a, int b)
        {
            if (depth[a]<depth[b])
                swap(a,b); // a should have the max depth

            int diff = depth[a]-depth[b];

            if (diff)
                a = kthanc(a, diff);

            if (a==b)
                return a;

            for (int i=log-1 ; i>-1 ; i--)
            {
                int ca=up[a][i];
                int cb=up[b][i];
                if (ca != cb)
                {
                    a=ca;
                    b=cb;
                }
            }

            return up[a][0];
        }

        int dist(int a, int b)
        {
            return depth[a]+depth[b]-2*depth[lca(a,b)];
        }
};

class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int e = edges.size();
        int v = e+1;
        BinaryLifting bl = BinaryLifting(v);

        for (const auto &ee : edges) {
            int x = ee[0];
            int y = ee[1];
            int w = ee[2];

            bl.add(x, y, w);
        }

        bl.dfs(0);

        int q = queries.size();
        vector<int> ans;

        for (int i=0 ; i<q ; i++) {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2];

            int ab = bl.lca(a, b);
            int ac = bl.lca(a, c);
            int bc = bl.lca(b, c);

            int _lca = bl.lca(ab, c);
            int res;

            if (_lca == ab && ab == ac && ac == bc) {
                res = bl.weight[a] + bl.weight[b] + bl.weight[c] - 3*bl.weight[_lca];
            } else {
                if (ab != _lca) {
                    res = bl.weight[a] - bl.weight[ab] + bl.weight[b] - bl.weight[_lca] + bl.weight[c] - bl.weight[_lca];
                } else if (ac != _lca) {
                    res = bl.weight[a] - bl.weight[ac] + bl.weight[c] - bl.weight[_lca] + bl.weight[b] - bl.weight[_lca];
                } else {
                    res = bl.weight[c] - bl.weight[bc] + bl.weight[b] - bl.weight[_lca] + bl.weight[a] - bl.weight[_lca];
                }
            }
            ans.push_back(res);
        }

        return ans;
    }
};
