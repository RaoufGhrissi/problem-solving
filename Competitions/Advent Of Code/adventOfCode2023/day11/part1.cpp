#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll unsigned long long

using namespace std;

set<int> extendedRows;
set<int> extendedCols;

const ll extention = 1e6;

bool safe(int i, int j, int n, int m) {
    return i>-1 && i<n && j>-1 && j<m;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

ll dist[300][300];

void initDist(int n, int m) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            dist[i][j] = 1e18;
        }
    }
}

ll compute(int n, int m, vector<string> &v) {
    ll tot = 0;
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            if (v[i][j] == '#')
                tot += dist[i][j];
        }
    }

    return tot;
}

ll augmentedBfs(int i, int j, int &n, int &m, vector<string> &v) {
    queue<pp> q;
    initDist(n, m);
    q.push({i, j});
    dist[i][j] = 0;
    while(!q.empty()) {
        pp parent = q.front();
        i = parent.first;
        j = parent.second;
        q.pop();

        for (int d=0 ; d<4 ;d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (!safe(x, y, n, m))
                continue;

            ll distt = 1;
            if (x != i) { // vertical mvt
                if ((x == i+1 && extendedRows.count(i)) || (x==i-1 && extendedRows.count(x))) { // down mvt or top mvt
                    distt = extention;
                }
            } else { // horizental mvt
                if ((y == j+1 && extendedCols.count(j)) || (y==j-1 && extendedCols.count(y))) { // right mvt or left mvt
                    distt = extention;
                }
            }

            if (dist[x][y] > dist[i][j] + distt) {
                dist[x][y] = dist[i][j] + distt;
                q.push({x, y});
            }
        }
    }

    return compute(n, m, v);
}

ll solve() {
    ifstream file("a.txt");
    ll ans = 0;
    vector<string> v;
    int l = -1;
    for (string s; getline(file, s);) {
        l++;
        bool contains = 0;
        for (auto &c:s) {
            if (c == '#') {
                contains = 1;
                break;
            }
        }

        if (!contains) {
            extendedRows.insert(l);
        }

        v.push_back(s);
    }

    int n = v.size();
    int m = v[0].size();

    for (int col=0 ; col<m ; col++) {
        bool contains = 0;
        for (int line=0 ; line<n ; line++) {
            if (v[line][col] == '#') {
                contains = 1;
                break;
            }
        }

        if (!contains) {
            extendedCols.insert(col);
        }
    }

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            if (v[i][j] == '#') {
                ans += augmentedBfs(i, j, n, m, v);
                v[i][j] = '.';
            }
        }
    }

    
    return ans;
}

int main() {
    cout<<solve();
    return 0;
}