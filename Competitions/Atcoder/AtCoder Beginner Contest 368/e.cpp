    #include <bits/stdc++.h>
    #define ll long long
    #define pp pair<ll, ll>
    using namespace std;

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
                dist[i] = 0;
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
        
        void dijkistra(vector<vector<vector<int>>> &dest, vector<vector<int>> &v, int x)
        {
            priority_queue<pp> pq;

            for (int i=0 ; i<n ; i++) {
                dist[i] = v[i][2];
                if (!i)
                    dist[i] += x;
            }

            pq.push({dist[0], 0});

            while(!pq.empty()) {
                pp parent = pq.top();
                pq.pop();

                ll d = parent.first;
                ll i = parent.second;

                if (d < dist[i])
                    continue;

                vector<int> train = v[i];

                int destination = train[1];
                int departure = train[2];
                int arrival = train[3];

                int duration = arrival - departure;
                int delayed_arrival = d + duration;

                vector<vector<int>> stations = dest[destination];

                int ii = 0;
                int sz = stations.size();

                if (!sz) continue;
                int jj = sz-1;

                while(ii<jj) {
                    int mid = (ii+jj)/2;

                    if (stations[mid][0] >= arrival) {
                        jj = mid;
                    } else {
                        ii = mid+1;
                    }
                }

                if (stations[ii][0] < arrival)
                    continue;

                for (int j=ii ; j<sz ; j++) {
                    int next_train = stations[j][2];
                    int start = stations[j][0];

                    if (delayed_arrival <= start) break;
                    
                    if (delayed_arrival > dist[next_train]) {
                        dist[next_train] = delayed_arrival;
                        pq.push({dist[next_train], next_train});
                    }
                }
            }

            for (int i=1 ; i<n ; i++) {
                cout<<dist[i] - v[i][2]<<" ";
            }
        }
    };

    void solve() {
        freopen("a.txt", "r", stdin);
        int t = 1;
        //cin>>t;

        while(t--) {
            int n, m, x;

            cin>>n>>m>>x;

            vector<vector<int>> v;
            vector<vector<vector<int>>> dest(n+1);

            Graph g = Graph(m);

            for (int i=0 ; i<m ; i++) {
                int a, b, s, e;
                cin>>a>>b>>s>>e;

                v.push_back({a, b, s, e});
                dest[a].push_back({s, e, i});
            }

            for (int i=1 ; i<=n ; i++)
                sort(dest[i].begin(), dest[i].end());

            g.dijkistra(dest, v, x);
    }
    }

    int main() {
        solve();
        return 0;
    }