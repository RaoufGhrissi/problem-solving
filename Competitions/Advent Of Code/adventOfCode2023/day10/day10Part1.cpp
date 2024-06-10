#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

map<pp, set<char>> possible = {
    {{-1, 0}, {'7', '|', 'F'}},
    {{0, -1}, {'L', '-', 'F'}},
    {{0, 1}, {'J', '-', '7'}},
    {{1, 0}, {'|', 'L', 'J'}},
};

unordered_map<char, vector<pp>> directions = {
    {'S', {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}},
    {'|', {{-1, 0}, {1, 0}}},
    {'-', {{0, -1}, {0, 1}}},
    {'7', {{0, -1}, {1, 0}}},
    {'L', {{-1, 0}, {0, 1}}},
    {'J', {{-1, 0}, {0, -1}}},
    {'F', {{1, 0}, {0, 1}}},
};

bool safe(int i, int j, int n, int m) {
    return i>-1 && i<n && j>-1 && j<m;
}

int augmentedBfs(int i, int j, int &n, int &m, vector<string> &v) {
    queue<pp> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    q.push({i, j});
    dist[i][j] = 0;
    int ans = 0;
    while(!q.empty()) {
        pp parent = q.front();
        i = parent.first;
        j = parent.second;
        q.pop();

        for (auto &dir: directions[v[i][j]]) {
            int x = i + dir.first;
            int y = j + dir.second;

            if (safe(x, y, n, m) && possible[dir].count(v[x][y]) && (dist[x][y] > dist[i][j] + 1)) {
                dist[x][y] = dist[i][j] + 1;
                ans = max(ans, dist[x][y]);
                q.push({x, y});
            }
        }
    }

    return ans;
}

int solve() {
    ifstream file("a.txt");
    int ans = 0;
    int n, m;
    vector<string> v;
    for (string s; getline(file, s);) {
        v.push_back(s);
    }

    n = v.size();
    m = v[0].size();

    int x = -1, y;
    for (int i=0 ; i<n ; i++) {
        if (x>-1) break;
        for (int j=0 ; j<m ; j++) {
            if (v[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
    }

    return augmentedBfs(x, y, n, m, v);
    
}

int main() {
    cout<<solve();
    return 0;
}