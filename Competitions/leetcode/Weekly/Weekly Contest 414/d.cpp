#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

#define st pair<int, pair<int, set<int>>>

using namespace std;

class Compressor {
    public:
        set<int> v;
        map<int, int> match;
        map<int, int> inversedMatch;
        int last;

    Compressor(vector<int> a) {
        for (auto &e:a)
            v.insert(e);
        
        build();
    }

    void build() {
        last = 0;
        for (auto &a: v) {
            match[a] = last;
            inversedMatch[last] = a;
            last++;
        }
    }
};

class Solution {
public:
    static const int dir = 8;
    int n = 50;
    int dx[dir] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[dir] = {-2, -1, 1, 2, 2, 1, -1, -2};

    bool safe(int i, int j) {
        return i>-1 && i<n && j>-1 && j<n;
    }

    int dist[16][16][10][10];

    void dijkistra(int x, int y, int mx, int my) {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;

        for (int i=0 ; i<50 ; i++) {
            for (int j=0 ; j<50 ; j++) {
                dist[mx][my][i][j] = 1e9;
            }
        }
        dist[mx][my][x][y] = 0;
        pq.push({dist[mx][my][x][y], x, y});

        while(!pq.empty())
        {
            vector<ll> parent = pq.top();
            pq.pop();

            ll d = parent[0];
            x = parent[1];
            y = parent[2];

            if (d > dist[mx][my][x][y])
                continue;

            for (int dd=0 ; dd<dir ; dd++) {
                int i = x + dx[dd];
                int j = y + dy[dd];
                if (safe(i, j) && dist[mx][my][i][j] > d + 1) {
                    dist[mx][my][i][j] = d + 1;
                    pq.push({dist[mx][my][i][j], i, j});
                }
            }
        }
    }

    int dp[16][16][1<<3][2];

    int rec(int x, int y, int mask, int alice, Compressor &xx, Compressor &yy, vector<vector<int>>& pos, int &sz) {
        if (mask == ((1<<sz) - 1))
            return 0;

        int &ans = dp[x][y][mask][alice];

        if (ans != -1)
            return ans;

        ans = alice ? 0 : 1e9;
        for (int i=0 ; i<sz ; i++) {
            int msk = 1<<i;
            if (msk && mask) continue;

            int a = pos[i][0];
            int b = pos[i][1];

            if (dist[x][y][a][b] == 1e9) continue;

            if (alice) {
                ans = max(ans, dist[x][y][a][b] + rec(xx.match[a], yy.match[b], mask | msk, 0, xx, yy, pos, sz));
            } else {
                ans = min(ans, dist[x][y][a][b] + rec(xx.match[a], yy.match[b], mask | msk, 0, xx, yy, pos, sz));
            }
        }

        return ans;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& pos) {
        vector<int> posX = {kx}, posY = {ky};

        for (auto &p:pos) {
            posX.push_back(p[0]);
            posY.push_back(p[1]);
        }

        Compressor xx = Compressor(posX);
        Compressor yy = Compressor(posY);

        dijkistra(kx, ky, xx.match[kx], yy.match[ky]);
        for (auto &p:pos) {
            int x = p[0];
            int y = p[1];
            dijkistra(x, y, xx.match[x], yy.match[y]);
        }

        memset(dp, -1, sizeof dp);

        int sz = pos.size();
        return rec(xx.match[kx], yy.match[ky], 0, 1, xx, yy, pos, sz);
    }
};

int main() {
    vector<vector<int>> v = {{1, 2}, {2, 4}};
    cout<<Solution().maxMoves(0, 2, v);
}