#include <bits/stdc++.h>
#define  ll long long
#define pp pair<int, int>
#define inf 1e18
using namespace std;

int dx[2] = {0, 1};
int dy[2] = {1, 0};
 
bool safe(int i, int j, int &n, int &m) {
    return i>-1 && j>-1 && i<n && j<m;
}

class DsuMaze {
    public:
        vector<vector<pp>> parent;
        vector<vector<int>> rank;
        int n, m;

        DsuMaze(int _n, int _m) {
            n = _n;
            m = _m;

            parent.resize(n, vector<pp>(m));
            rank.resize(n, vector<int>(m));

            for (int i=0 ; i<n ; i++) {
                for (int j=0 ; j<m ; j++) {
                    parent[i][j] = {i, j};
                    rank[i][j] = 1;
                }
            }
        }

        pp find(int i, int j) {
            if ((parent[i][j].first != i) || (parent[i][j].second != j))
                return parent[i][j] = find(parent[i][j].first, parent[i][j].second);

            return parent[i][j] = {i, j};
        }

        void unionn(int a, int b, int i, int j) {
            pp p1 = find(a, b);
            pp p2 = find(i, j);

            if (p1.first == p2.first && p1.second == p2.second)
                return;

            if (rank[p1.first][p1.second] < rank[p2.first][p2.second])
                swap(p1, p2);

            parent[p2.first][p2.second] = p1;
            rank[p1.first][p1.second] += rank[p2.first][p2.second];
            rank[p2.first][p2.second] = 0;
        }
};

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m;

        cin>>n>>m;

        vector<string> v(n);
        int used[n][m];

        memset(used, 0, sizeof used);

        for (int i=0 ; i<n ; i++)
            cin>>v[i];

        DsuMaze dsu = DsuMaze(n, m);
        int id = 0;
        vector<int> index;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (v[i][j] == '.') continue;
                for (int d=0 ; d<2 ; d++) {
                    int di = i + dx[d];
                    int dj = j + dy[d];
            
                    if (safe(di, dj, n, m) && v[di][dj] == '#') {
                        dsu.unionn(i, j, di, dj);
                    }
                }
            }
        }

        int ans = 0;
        int cnt = 0;

        for (int i=0 ; i<n ; i++) {
            int res = 0;
            cnt++;

            for (int j=0 ; j<m ; j++) {
                pp parent = dsu.find(i, j);
                if (v[i][j] == '.')
                    res++;
                else if (used[parent.first][parent.second] != cnt) {
                    res += dsu.rank[parent.first][parent.second];
                    used[parent.first][parent.second] = cnt;       
                }

                if (i>0 && v[i-1][j] == '#') {
                    parent = dsu.find(i-1, j);
                    if (used[parent.first][parent.second] != cnt) {
                        res += dsu.rank[parent.first][parent.second];
                        used[parent.first][parent.second] = cnt;
                    }
                }
    
                if (i+1 < n && v[i+1][j] == '#') {
                    parent = dsu.find(i+1, j);
                    if (used[parent.first][parent.second] != cnt) {
                        res += dsu.rank[parent.first][parent.second];
                        used[parent.first][parent.second] = cnt;
                    }
                }
            }

            ans = max(ans, res);
        }

        for (int col=0 ; col<m ; col++) { // col
            int res = 0;
            
            cnt++;

            for (int l=0 ; l<n ; l++) { // lines"
                pp parent = dsu.find(l, col);
                if (v[l][col] == '.')
                    res++;
                else if (used[parent.first][parent.second] != cnt) {
                    res += dsu.rank[parent.first][parent.second];
                    used[parent.first][parent.second] = cnt;   
                }

                if (col>0 && v[l][col-1] == '#') {
                    parent = dsu.find(l, col-1);
                    if (used[parent.first][parent.second] != cnt) {
                        res += dsu.rank[parent.first][parent.second];
                        used[parent.first][parent.second] = cnt;
                    }
                }
                
                if (col+1 < m && v[l][col+1] == '#') {
                    parent = dsu.find(l, col+1);
                    if (used[parent.first][parent.second] != cnt) {
                        res += dsu.rank[parent.first][parent.second];
                        used[parent.first][parent.second] = cnt;
                    }
                }
            }

            ans = max(ans, res);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}