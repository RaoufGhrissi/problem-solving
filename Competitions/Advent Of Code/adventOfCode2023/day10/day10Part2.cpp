#include <bits/stdc++.h>
#define pp pair<int,int>

using namespace std;

set<char> canGoright = {'L', '-', '=', 'F'};
set<char> canGoLeft = {'J', '-', '=', '7'};
set<char> canGoTop = {'|', 'T', 'L', 'J'};
set<char> canGoButtom = {'7', 'T', '|', 'F'};

map<pp, set<char>> possible = {
    {{-1, 0}, canGoButtom},
    {{0, -1}, canGoright},
    {{0, 1}, canGoLeft},
    {{1, 0}, canGoTop},
};

unordered_map<char, vector<pp>> directions = {
    {'S', {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}},
    {'|', {{-1, 0}, {1, 0}}},
    {'T', {{-1, 0}, {1, 0}}},
    {'-', {{0, -1}, {0, 1}}},
    {'=', {{0, -1}, {0, 1}}},
    {'7', {{0, -1}, {1, 0}}},
    {'L', {{-1, 0}, {0, 1}}},
    {'J', {{-1, 0}, {0, -1}}},
    {'F', {{1, 0}, {0, 1}}},
};

bool safe(int i, int j, int n, int m) {
    return i>-1 && i<n && j>-1 && j<m;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

bool vis[300][300];
bool used[300][300];

bool dfs(int i, int j, int &n, int &m, vector<string> &v, int &tot) {
    used[i][j] = 1;
    if (v[i][j] != '#' && v[i][j] != '=' && v[i][j] != 'T')
        tot++;

    bool ans = 1; 
    if (!i || i==n-1 || !j || j==m-1)
        ans = 0;
    
    for (int d=0 ; d<4 ; d++) {
        int x = i + dx[d];
        int y = j + dy[d];

        if (safe(x, y, n, m) && !vis[x][y] && !used[x][y]) {
            bool res = dfs(x, y, n, m, v, tot);
            if (!res) {
                ans = 0;
            }
        }
    }

    return ans;
}

void augmentedBfs(int i, int j, int &n, int &m, vector<string> &v) {
    queue<pp> q;
    q.push({i, j});
    vis[i][j] = 1;
    int ans = 0;
    while(!q.empty()) {
        pp parent = q.front();
        i = parent.first;
        j = parent.second;
        q.pop();

        for (auto &dir: directions[v[i][j]]) {
            int x = i + dir.first;
            int y = j + dir.second;

            if (safe(x, y, n, m) && possible[dir].count(v[x][y]) && !vis[x][y]) {
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }
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

    vector<string> inter;
    for (int i=0 ; i<n ; i++) {
        string s = "";
        string s1 = v[i];        
        for (int j=0 ; j<m-1 ; j++) {
            s += s1[j];
            if (s1[j] == 'S' || (canGoright.count(s1[j]) && (s1[j+1] == 'S' || canGoLeft.count(s1[j+1])))) {
                s += '=';
            } else {
                s += '#';
            }
        }
        s += s1[m-1];
        inter.push_back(s);
    }
    m = inter[0].size();

    vector<string> edited;
    for (int i=0 ; i<n-1 ; i++) {
        string s = "";
        string actual = inter[i];
        string next = inter[i+1];
        edited.push_back(actual);

        for (int j=0 ; j<m ; j++) {
            if (actual[j] == 'S' || (canGoButtom.count(actual[j]) && (next[j] == 'S' || canGoTop.count(next[j])))) {
                s += 'T';
            } else {
                s += '#';
            }
        }

        edited.push_back(s);
    }

    edited.push_back(inter[n-1]);

    n = edited.size();
    m = edited[0].size();

    int x = -1, y;
    for (int i=0 ; i<n ; i++) {
        if (x>-1) break;
        for (int j=0 ; j<m ; j++) {
            if (edited[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    augmentedBfs(x, y, n, m, edited);    
    memset(used, 0, sizeof(used));
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            
            if (used[i][j] || vis[i][j]) continue;
            int tot = 0;
            cout<<i<<" "<<j<<endl;
            bool res = dfs(i, j, n, m, edited, tot);
            if (res)
                ans += tot;
        }
    }

    return ans;
}

int main() {
    cout<<solve();
    return 0;
}