#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long
#define pp pair<int,int>

const int dir = 8;
int dx[dir] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[dir] = {1, 0, -1, 1, -1, 1, 0, -1};

bool safe(int &i, int &j, int &n, int &m) {
    return i>-1 && j>-1 && i<n && j<m;
}

int solve() {
    ifstream file("a.txt");
    ull ans = 0;
    vector<int> t;
    vector<string> v;
    for (string s; getline(file, s);) {
        v.push_back(s);
    }

    map<pp, vector<int>> gears;
    int m = v[0].size();
    int n = v.size();
    for (int i=0 ; i<n ; i++) {
        ull nb = 0;
        bool valid = 0;
        set<pp> actualGears;
        for (int j=0 ; j<m ; j++) {
            if (isdigit(v[i][j])) {
                nb = nb*10ull + (v[i][j]-'0')*1ull;
                for (int d=0 ; d<dir ; d++) {
                    int x = i+dx[d];
                    int y = j+dy[d];
                    if (safe(x, y, n, m) && !isdigit(v[x][y]) && v[x][y] != '.') {
                        valid = 1;
                        if (v[x][y] == '*') {
                            actualGears.insert({x, y});
                        }
                    }
                }
            }

            if (!isdigit(v[i][j]) || j==m-1) {
                if (valid) {
                    for (auto &g:actualGears) {
                        gears[g].push_back(nb);
                    }
                }

                valid = 0;
                nb = 0;
                actualGears.clear();
            }
        }
    }

    for (auto &a:gears) {
        if (a.second.size() == 2) {
            ans += a.second[0]*a.second[1];
        }
    }

    return ans;
    
}

int main() {
    cout<<solve();
    return 0;
}