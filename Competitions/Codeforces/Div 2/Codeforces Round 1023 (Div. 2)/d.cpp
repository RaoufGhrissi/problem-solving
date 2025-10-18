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

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int mod = 1e9 + 7;


bool safe(int i, int j, int n, int m) {
    return i>-1 && i<n && j>-1 && j<m;
}

class DsuMaze {
    public:
        vector<vector<pp>> parent;
        vector<vector<int>> rank;
        vector<vector<int>> edges;
        vector<vector<bool>> selfLoop;
        int n, m;

        DsuMaze(int _n, int _m) {
            n = _n;
            m = _m;

            parent.resize(n, vector<pp>(m));
            rank.resize(n, vector<int>(m));
            edges.resize(n, vector<int>(m));
            selfLoop.resize(n, vector<bool>(m));

            for (int i=0 ; i<n ; i++) {
                for (int j=0 ; j<m ; j++) {
                    parent[i][j] = {i, j};
                    rank[i][j] = 1;
                    edges[i][j] = 0;
                    selfLoop[i][j] = 0;
                }
            }
        }

        pp find(int i, int j) {
            if ((parent[i][j].first != i) || (parent[i][j].second != j))
                return parent[i][j] = find(parent[i][j].first, parent[i][j].second);

            return parent[i][j] = {i, j};
        }

        void unionn(int a, int b, int i, int j) {
            bool self = a==i && b==j;
            pp p1 = find(a, b);
            pp p2 = find(i, j);

            if (p1.first == p2.first && p1.second == p2.second) {
                edges[p1.first][p1.second]++;
                selfLoop[p1.first][p1.second] = selfLoop[p1.first][p1.second] || self;
                return;
            }

            if (rank[p1.first][p1.second] < rank[p2.first][p2.second])
                swap(p1, p2);

            parent[p2.first][p2.second] = p1;
            rank[p1.first][p1.second] += rank[p2.first][p2.second];
            rank[p2.first][p2.second] = 0;
            edges[p1.first][p1.second] += 1 + edges[p2.first][p2.second];
            edges[p2.first][p2.second] = 0;
            selfLoop[p1.first][p1.second] = selfLoop[p1.first][p1.second] || selfLoop[p2.first][p2.second] || self;
        }
};

int dist(int i, int j, int x, int y) {
    return abs(i-x) + abs(j-y);
}

bool isConnected(int i, int j, int x, int y, int n, int m) {
    for (int d=0 ; d<4 ; d++) {
        int di = i + dx[d];
        int dj = j + dy[d];

        if (safe(di, dj, n, m) && di==x && dj==y) {
            return 1;
        }
    }

    return 0;
}

int cnt = 0;


void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, m ,k;
        cin>>n>>m>>k;

        k++;
        vector<pp> v(k);
        set<pp> in;
        for (int i=0 ; i<k ; i++) {
            cin>>v[i].first>>v[i].second;
            v[i].first--;
            v[i].second--;
            in.insert(v[i]);
        }

        DsuMaze dsu = DsuMaze(n, m);
        bool ok = 1;
        pp pos1, pos2;
        set<pp> used;

        for (int i=k-2 ; i>-1 ; i--) {
            int x = v[i].first;
            int y = v[i].second;
            
            int nx = v[i+1].first;
            int ny = v[i+1].second;

            if (dist(x, y, nx, ny) != 2) {
                ok = 0;
                break;
            }

            pos1.first = -1;
            pos2.first = -1;

            for (int d=0 ; d<4 ; d++) {
                int di = x+dx[d];
                int dj = y+dy[d];

                if (safe(di, dj, n, m) && !in.count({di, dj}) && isConnected(di, dj, nx, ny, n, m)) {
                    if (pos1.first == -1) {
                        pos1 = {di, dj};
                    } else {
                        pos2 = {di, dj};
                    }
                }   
            }

            if (pos1.first == -1) {
                ok = 0;
                continue;
            }

            if (pos2.first == -1) {
                dsu.unionn(pos1.first, pos1.second, pos1.first, pos1.second);
                used.insert(pos1);
            } else {
                dsu.unionn(pos1.first, pos1.second, pos2.first, pos2.second);
                used.insert(pos1);
                used.insert(pos2);
            }
        }

        if (!ok) {
            cout<<0<<endl;
            continue;
        }

        ll ans = 1;

        for (auto &[f,s]:used) {
            if (dsu.rank[f][s]) { // parent
                int v = dsu.rank[f][s];
                int e = dsu.edges[f][s];
                bool self = dsu.selfLoop[f][s];

                if (e == v-1) {
                    ans = (ans * v)%mod;
                } else if (e == v) {
                    if (!self) {
                        ans = (ans * 2)%mod;
                    }
                } else {
                    ok = 0;
                    break;
                }
            }
        }

        if (!ok) {
            cout<<0<<endl;
            continue;
        }


        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}