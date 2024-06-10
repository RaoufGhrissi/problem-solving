#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define INF (ll)1e18

using namespace std;

class Graph {
    public:
        vector<set<pp>> edges;
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
            dist[i] = INF;
            vis[i] = 0;
            anc[i] = 0;
        }
    }

    void add(int a, int b, int w = 1) {
        edges[a].insert({b, w});

        if (!directed) {
            edges[b].insert({a, w});
        }
    }

    bool isCyclic(int node) {
        vis[node] = 1;
        anc[node] = 1;

        for (auto &c:edges[node]) {
            int child = c.first;

            if (anc[child])
                return true;

            if (!vis[child] && isCyclic(child))
                return true;
        }

        anc[node] = 0;

        return false;
    }

    vector<int> dijkistra(int node)
    {
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        dist[node] = 0;
        pq.push({dist[node], node});
        vector<int> ans;

        while(!pq.empty())
        {
            pp parent = pq.top();
            pq.pop();

            int d = parent.first;
            ll index = parent.second;

            if (d>dist[index])
                continue;

            ans.push_back(index);

            for (auto childPair:edges[index])
            {
                ll child = childPair.first;
                ll dFromParentToChild = childPair.second;
                if (dist[child] > dFromParentToChild && dFromParentToChild >= d)
                {
                    dist[child] = dFromParentToChild;
                    pq.push({dist[child], child});
                }

            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    } 
};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, k;
        cin>>n>>k;

        Graph g = Graph(n);
        vector<bool> root(n, 1);
        while(k--) {
            int prev;
            for (int i=0 ; i<n ; i++) {
                int x;
                cin>>x;
                x--;
                if (i>1) {
                    g.add(prev, x);
                    root[x] = 0;
                }

                prev = x;
            }
        }

        bool found = 0;
        bool cycle = 0;
        for (int i=0 ; i<n ; i++) {
            if (!root[i]) continue;

            found = 1;
            if (g.isCyclic(i)) {
                cycle = 1;
                break;
            }
        }

        if (found && !cycle) {
            cout<<"YES";
        } else {
            cout<<"NO";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}