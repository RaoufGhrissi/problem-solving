#include <bits/stdc++.h>
#define ll unsigned long long
#define pp pair<int, int>
using namespace std;

unordered_map<int, pp> directions = {
    {0, {0, 1}}, // right
    {1, {0, -1}}, // left
    {2, {-1, 0}}, // top
    {3, {1, 0}}, // down
};

unordered_map<int, int> inverse = {
    {0, 1},
    {1, 0},
    {2, 3},
    {3, 2},
};

int dist[1000][1000][4][4];

bool safe(int i, int j, int &n, int &m) {
    return i>-1 && j>-1 && i<n && j<m;
}

void initDist(int &n, int &m) {
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            for (int k=0 ; k<4 ; k++) {
                for (int c=0 ; c<4 ; c++) {
                    if (!i && !j)
                        dist[i][j][k][c] = 0;
                    else
                        dist[i][j][k][c] = 1e9;
                }
            }
        }
    }
}

int dijkistra(vector<string> &v, int &n, int &m) {
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0, 0, 0});
    pq.push({0, 0, 0, 1, 0});
    pq.push({0, 0, 0, 2, 0});
    pq.push({0, 0, 0, 3, 0}); // {dist, i, j, previous direction, total consecutive}
    initDist(n, m);

    while(!pq.empty()) {
        vector<int> t = pq.top();
        pq.pop();
        int d = t[0];
        int i = t[1];
        int j = t[2];
        int dir = t[3];
        int cnt = t[4];

        for (auto &kv: directions) {
            int _direction = kv.first;
            pp value = kv.second;

            int x = i + value.first;
            int y = j + value.second;

            if (!safe(x, y, n, m) || inverse[_direction] == dir)
                continue;

            int newCnt = _direction == dir ? cnt+1 : 1;

            if (newCnt > 3)
                continue;

            int val = dist[i][j][dir][cnt] + (v[x][y]-'0');
            if (dist[x][y][_direction][newCnt] > val) {
                dist[x][y][_direction][newCnt] = val;
                pq.push({dist[x][y][_direction][newCnt], x, y, _direction, newCnt});
            }
        }
    }

    int ans = 1e9;
    for (int d=0 ; d<4 ; d++) {
        for (int c=0 ; c<4 ; c++) {
            ans = min(ans, dist[n-1][m-1][d][c]);
        }
    }

    // backtracking to display the path

    // int x = n-1;
    // int y = m-1;
    // int d = 3;
    // int c = 3;

    // while (true) {
    //     int val = v[x][y] - '0';
    //     cout<<x<<" "<<y<<endl;
    //     if (!x && !y)
    //         break;

    //     int nextVal = dist[x][y][d][c] - val;
    //     for (auto &kv:directions) {
    //         int i = x+kv.second.first;
    //         int j = y+kv.second.second;
            
    //         if (!safe(i, j, n, m)) continue;
    //         if (c>1) {
    //             if (inverse[kv.first] != d) continue;
    //             if (dist[i][j][d][c-1] == nextVal) {
    //                 x = i;
    //                 y = j;
    //                 c--;
    //                 break;
    //             }
    //         } else {
    //             for (int k=0 ; k<4 ; k++) {
    //                 for (int f=0 ; f<4 ; f++) {
    //                     if (dist[i][j][k][f] == nextVal) {
    //                         x = i;
    //                         y = j;
    //                         c = f;
    //                         d = k;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    return ans;
}


ll solve() {
    ll ans = 0;
    vector<string> v;
    ifstream file("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day17/a.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            v.push_back(line);
        }
    }

    int n = v.size();
    int m = v[0].size();

    return dijkistra(v, n, m);
}

int main() {
    cout << solve() << endl;
    return 0;
}
