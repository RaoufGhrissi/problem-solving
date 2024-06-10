#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18
//https://codeforces.com/contest/1941/problem/G

#define st pair<int, pair<int, set<int>>>

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

class Graph {
    public:
        vector<vector<pp>> edges;
        int n;
        bool directed;
        vector<ll> dist;
        vector<bool> vis;
        vector<bool> anc;

    Graph(int _n, bool _directed = true) {
        n = _n;
        edges.resize(n);
        directed = _directed;
        init();
    }

    void init() {
        dist.resize(n);
        vis.resize(n);
        anc.resize(n);

        for (int i=0 ; i<n ; i++) {
            dist[i] = inf;
            vis[i] = 0;
            anc[i] = 0;
        }
    }

    void add(int a, int b, int w = 1) {
        edges[a].push_back({b, w});

        if (!directed) {
            edges[b].push_back({a, w});
        }
    }

    bool isCyclic(int node) {
        vis[node] = 1;
        anc[node] = 1;

        for (auto &c:edges[node]) {
            int child = c.first;

            if (anc[node])
                return true;

            if (!vis[child] && isCyclic(child))
                return true;
        }

        anc[node] = 0;

        return false;
    }

    int bfs01(int src, int dest)
    {
        deque<pp> pq;
        dist[src] = 0;
        pq.push_front({dist[src], src});

        while(!pq.empty())
        {
            pp parent = pq.front();
            pq.pop_front();

            int d = parent.first;
            int node = parent.second;

            if (d>dist[node])
                continue;

            for (auto childPair:edges[node])
            {
                int child = childPair.first;
                int dd = childPair.second;

                if (dist[child] > dd + d)
                {
                    dist[child] = dd + d;
                    if (dd == 1)
                        pq.push_back({dist[child], child});
                    else
                        pq.push_front({dist[child], child});
                }

            }
        }

        return dist[dest];
    } 
};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, a, b, x, y, c;

        cin>>n>>m;
        vector<int> s(m), d(m), col(m);

        for (int i=0 ; i<m ; i++) {
            cin>>s[i]>>d[i]>>col[i];
            s[i]--;
            d[i]--;
            col[i]--;
        }

        Compressor comp = Compressor(col);
        int coll = comp.last;

        Graph g = Graph(n+coll);
        for (int i=0 ; i<m ; i++) {
            c = comp.match[col[i]];
            g.add(s[i], c+n, 1);
            g.add(d[i], c+n, 1);
            g.add(c+n, s[i], 0);
            g.add(c+n, d[i], 0);
        }

        cin>>a>>b;
        a--;
        b--;

        cout<<g.bfs01(a, b)<<endl;
    }
}

int main() {
    solve();
    return 0;
}