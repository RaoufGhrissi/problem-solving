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

const ll mod = 1e9 + 7;
int t,n;

//https://cp-algorithms.com/algebra/module-inverse.html
int inv(int a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

class BinaryLifting {
    public:
        vector<vector<int>> up;
        vector<int> depth;
        vector<ll> weight;
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
            weight[0] = 1;  
        }

        void add(int a, int b, int w) {
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }

        void dfs(int node, int parent)
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
                
                weight[id] = (weight[node] * w)%mod;
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

int main()
{
    FAST;
    //freopen("a.txt", "r", stdin);
    t = 1;
    //cin>>t;

    while(t--)
    {
        cin>>n;

        BinaryLifting bl = BinaryLifting(n);
        
        for (int i=0 ; i<n-1 ; i++)
        {
            int x, y, w;
            cin>>x>>y>>w;
            bl.add(--x, --y, w);
        }

        bl.dfs(0, -1);
        int q;
        cin>>q;
        while(q--)
        {
            int x, y;
            cin>>x>>y;
            x--;
            y--;

            int lc = bl.lca(x, y);

            ll ans = (bl.weight[x] * bl.weight[y]) % mod;
            ll rev = inv(bl.weight[lc]);
            rev = (rev * rev)%mod;
            ans = (ans * rev)%mod;

            cout<<ans;
            newL;
        }
    }

    return 0;
}