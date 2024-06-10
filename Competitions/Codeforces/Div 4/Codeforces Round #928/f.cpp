#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

bool safe(int i, int j) {
    return i>-1 && j>-1 && i<7 && j<7;
}

int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

bool isValid(vector<string> &v, vector<pp> &t) {
    for (auto &a:t) {
        int i = a.first;
        int j = a.second;
        if (v[i][j] == 'W') continue;
        int cnt = 0;
            
        for (int d=0 ; d<4 ; d++) {
            int di = i+dx[d];
            int dj = j+dy[d];
            if (safe(di, dj) && v[di][dj] == 'B') {
                cnt++;
            } else {
                break;
            }
        }
        
        if (cnt == 4) {
            return 0;
        }
    }

    return 1;
}

void backtrack(int x, int res, int &ans, vector<string> &v, vector<pp> &t) {
    if (res > ans) {
        return;
    }

    if (x==t.size()) {
        if (!isValid(v, t))
            return;

        ans = min(ans, res);
        return;
    }

    int i = t[x].first;
    int j = t[x].second;

    backtrack(x+1, res, ans, v, t);
    
    if (v[i][j] == 'W') {
        return;
    }

    v[i][j] = 'W';
    backtrack(x+1, res+1, ans, v, t);
    v[i][j] = 'B';
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        vector<string> v(7);
        for (int i=0 ; i<7 ; i++) {
            cin>>v[i];
        }

        vector<pp> t;

        for (int i=0 ; i<7 ; i++) {
            int j = i&1 ? 1 : 0;
            for (; j<7 ; j+=2) {
                t.push_back({i, j});
            }
        }

        int ans = 0;
        if (!t.empty()) {
            int res = 4;
            backtrack(0, 0, res, v, t);

            ans += res;
        }

        t.clear();

        for (int i=0 ; i<7 ; i++) {
            int j = i&1 ? 0 : 1;
            for (; j<7 ; j+=2) {
                t.push_back({i, j});
            }
        }

        if (!t.empty()) {
            int res = 4;
            backtrack(0, 0, res, v, t);
    
            ans += res;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}