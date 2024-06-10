#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool vis[6][6];
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    bool safe(int i, int j, int n, int m) {
        return i>-1 && j>-1 && i<n && j<m;
    }

    bool dfs(int i, int j, int &n, int &m, string &s, vector<vector<char>>& v, int id) {
        if (id == s.size()) return 1;
        vis[i][j] = 1;

        for (int d=0 ; d<4 ; d++) {
            int di = i+dx[d];
            int dj = j+dy[d];

            if (safe(di, dj, n, m) && !vis[di][dj] && v[di][dj] == s[id]) {
                if (dfs(di, dj, n, m, s, v, id+1)) return 1;
            }
        }

        vis[i][j] = 0;
        return 0;
    }

    bool exist(vector<vector<char>>& v, string s) {
        int n = v.size();
        int m = v[0].size();

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<m ; j++) {
                if (v[i][j] == s[0] && dfs(i, j, n, m, s, v, 1)) return 1;
            }
        }

        return 0;   
    }
};