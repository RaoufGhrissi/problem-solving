#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

class Graph {
    public:
        vector<vector<pp>> edges;
        int n;
        bool directed;
        vector<vector<ll>> dist;
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
            dist[i].resize(2);

            dist[i][0] = inf;
            dist[i][1] = inf;

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

    void dijkistra(int node = 0) {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
        dist[node][0] = 0;
        pq.push({dist[node][0], node});
        vector<ll> topp;

        while(!pq.empty())
        {
            topp = pq.top();
            pq.pop();

            ll d = topp[0];
            ll node = topp[1];
            ll parity = d&1;

            if (d > dist[node][parity])
                continue;

            for (auto childPair:edges[node])
            {
                ll child = childPair.first;
                ll dFromParentToChild = childPair.second;

                ll new_dist = d + dFromParentToChild;
                ll new_parity = new_dist&1;

                if (dist[child][new_parity] > new_dist) {
                    dist[child][new_parity] = new_dist;
                    pq.push({dist[child][new_parity], child});
                }
            }
        }
    } 
};

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, m, l;
        cin>>n>>m>>l;

        vector<int> v(l);
        for (int i=0 ; i<l ; i++)
            cin>>v[i];

        sort(v.begin(), v.end());

        Graph graph = Graph(n, 0);

        for (int i=0 ; i<m ; i++) {
            int x, y;
            cin>>x>>y;

            x--;
            y--;
            graph.add(x, y);
        }

        graph.dijkistra();

        int tot = 0;
        for (int i=0 ; i<l ; i++)
            tot += v[i];

        int totPair = -1, totImpair = -1;
        if (tot&1) {
            totImpair = tot;

            for (int i=0 ; i<l ; i++) {
                if (v[i]&1) {
                    totPair = totImpair - v[i];
                    break;
                }
            }
        } else {
            totPair = tot;
            for (int i=0 ; i<l ; i++) {
                if (v[i]&1) {
                    totImpair = totPair - v[i];
                    break;
                }
            }
        }

        string ans = "";
        for (int i=0 ; i<n ; i++) {
            if (totImpair >= graph.dist[i][1] || totPair >= graph.dist[i][0])
                ans += '1';
            else
                ans += '0';
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}