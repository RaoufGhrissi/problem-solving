#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long


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

    int m = v[0].size();
    int n = v.size();
    for (int i=0 ; i<n ; i++) {
        ull nb = 0;
        bool valid = 0;
        for (int j=0 ; j<m ; j++) {
            if (isdigit(v[i][j])) {
                nb = nb*10ull + (v[i][j]-'0')*1ull;
                if (!valid) {
                    for (int d=0 ; d<dir ; d++) {
                        int x = i+dx[d];
                        int y = j+dy[d];

                        if (safe(x, y, n, m) && !isdigit(v[x][y]) && v[x][y] != '.') {
                            valid = 1;
                            break;
                        }
                    }
                }
            }

            if (!isdigit(v[i][j]) || j==m-1) {
                if (valid) {
                    ans += nb;
                }

                valid = 0;
                nb = 0;
            }
        }
    }
    return ans;
    
}

int main() {
    cout<<solve();
    return 0;
}