#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll unsigned long long

using namespace std;

bool safe(int i, int j, int n, int m) {
    return i>-1 && i<n && j>-1 && j<m;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

ll dist[131][131];
unordered_map<pp, vector<vector<int>>> dist_per_start;

void initDist(int n, int m, vector<vector<int>> &dist) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            dist[i][j] = 1e18;
        }
    }
}

ll augmentedBfs(int i, int j, int start, int &n, int &m, vector<string> &v) {
    queue<pp> q;
    initDist(n, m, dist_per_start[{i, j}]);
    q.push({i, j});
    dist[i][j] = start;
    int ans = 0;
    while(!q.empty()) {
        pp parent = q.front();
        i = parent.first;
        j = parent.second;
        q.pop();

        for (int d=0 ; d<4 ;d++) {
            int x = i + dx[d];
            int y = j + dy[d];

            if (safe(x, y, n, m) && v[x][y] == '.' && dist[x][y] > dist[i][j] + 1 && dist[i][j] < 64) {
                dist[x][y] = dist[i][j] + 1;
                ans += !(dist[x][y]&1);
                q.push({x, y});
            }
        }
    }

    return ans+1;
}

ll solve() {
    ifstream file("a.txt");
    vector<string> v;
    for (string s; getline(file, s);) {        
        v.push_back(s);
    }

    int n = v.size();
    int m = v[0].size();

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            if (v[i][j] == 'S')
                return augmentedBfs(i, j, n, m, v);
        }
    }
    
    return 0;
}

int main() {
    cout<<solve();
    return 0;
}