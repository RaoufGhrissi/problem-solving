#include <bits/stdc++.h>
#define ll unsigned long long
#define pp pair<int, int>
using namespace std;

unordered_map<int, pp> directions = {
    {0, {0, 1}},
    {1, {0, -1}},
    {2, {-1, 0}},
    {3, {1, 0}},
};

unordered_map<int, unordered_map<char, vector<int>>> nextDir = {
    {
        0, {
            {'-', {0}},
            {'.', {0}},
            {'/', {2}},
            {'\\', {3}},
            {'|', {2, 3}},
        },
    },
    {
        1, {
            {'-', {1}},
            {'.', {1}},
            {'/', {3}},
            {'\\', {2}},
            {'|', {2, 3}},
        },
    },
    {
        2, {
            {'-', {0, 1}},
            {'.', {2}},
            {'/', {0}},
            {'\\', {1}},
            {'|', {2}},
        },
    },
    {
        3, {
            {'-', {0, 1}},
            {'.', {3}},
            {'/', {1}},
            {'\\', {0}},
            {'|', {3}},
        },
    },
};

bool vis[120][120][4];
bool used[120][120];

bool safe(int i, int j, int &n, int &m) {
    return i>-1 && j>-1 && i<n && j<m;
}

ll bfs(int a, int b, int d, vector<string> &v, int &n, int &m) {
    queue<vector<int>> q;
    q.push({a, b, d});
    vis[a][b][d] = 1;
    ll res = 1;
    used[a][b] = 1;
    while(!q.empty()) {
        vector<int> t = q.front();
        q.pop();
        int i = t[0];
        int j = t[1];
        int dir = t[2];

        for (auto &nxt: nextDir[dir][v[i][j]]) {
            int x = i + directions[nxt].first;
            int y = j + directions[nxt].second;

            if (safe(x, y, n, m) && !vis[x][y][nxt]) {
                vis[x][y][nxt] = 1;
                if (!used[x][y])
                    res++;
                used[x][y] = 1;
                q.push({x, y, nxt});
            }
        }
    }

    return res;
}


ll solve() {
    ll ans = 0;
    vector<string> v;
    ifstream file("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day16/a.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            v.push_back(line);
        }
    }

    int n = v.size();
    int m = v[0].size();
    
    
    // start from the top
    for (int col=0 ; col<m ; col++) {
        memset(vis, 0, sizeof vis);
        memset(used, 0, sizeof used);
        ans = max(ans, bfs(0, col, 3, v, n, m));
    }

    // start from the leftmost
    for (int line=0 ; line<n ; line++) {
        memset(vis, 0, sizeof vis);
        memset(used, 0, sizeof used);
        ans = max(ans, bfs(line, 0, 0, v, n, m));
    }

    // start from the rightmost
    for (int line=0 ; line<n ; line++) {
        memset(vis, 0, sizeof vis);
        memset(used, 0, sizeof used);
        ans = max(ans, bfs(line, m-1, 1, v, n, m));
    }

    // start from the buttom
    for (int col=0 ; col<m ; col++) {
        memset(vis, 0, sizeof vis);
        memset(used, 0, sizeof used);
        ans = max(ans, bfs(n-1, col, 2, v, n, m));
    }
    
    return ans;
}
int main() {
    cout << solve() << endl;
    return 0;
}
