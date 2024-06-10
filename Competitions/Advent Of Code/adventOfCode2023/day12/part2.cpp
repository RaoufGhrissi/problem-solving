#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll dp[110][110][110];

ll rec(int i, int j, int cnt, const string& s, const vector<int>& l) {
    if (i >= s.length()) {
        return j == l.size();
    }

    if (dp[i][j][cnt] != -1) {
        return dp[i][j][cnt];
    }

    dp[i][j][cnt] = 0;

    if (s[i] == '.') {
        if (!cnt) {
            dp[i][j][cnt] = rec(i+1, j, 0, s, l);
        }
    } else if (s[i] == '#') {
        if (j == l.size()) {
            return 0;
        }

        if (cnt+1 < l[j]) {
            dp[i][j][cnt] = rec(i+1, j, cnt+1, s, l);
        } else if (cnt+1 == l[j] && (i+1 == s.size() || s[i+1] != '#')) {
            dp[i][j][cnt] = rec(i+2, j+1, 0, s, l);
        }
    } else {
        if (j == l.size()) {
            dp[i][j][cnt] = rec(i+1, j, 0, s, l);
        } else if (cnt+1 < l[j]) {
            dp[i][j][cnt] = rec(i+1, j, cnt+1, s, l);
            if (!cnt) {
                dp[i][j][cnt] += rec(i+1, j, cnt, s, l);
            }
        } else if (cnt+1 == l[j]) {
            if (i+1 < s.size() && s[i+1] == '#') {
                if (!cnt) {
                    dp[i][j][cnt] = rec(i+1, j, 0, s, l);
                }
            } else {
                dp[i][j][cnt] = rec(i+2, j+1, 0, s, l);
                if (!cnt) {
                    dp[i][j][cnt] += rec(i+1, j, cnt, s, l);
                }
            }
        }
    }

    return dp[i][j][cnt];
}

ll solve() {
    ll ans = 0;

    ifstream file("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day12/a.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            size_t pos = line.find(' ');
            string s = line.substr(0, pos);
            line.erase(0, pos + 1);
            
            string t = s;
            int n = 4;
            while(n--)
                s += '?' + t;
            n = 4;
            t = line;
            while(n--)
                line += ',' + t;
            vector<int> l;
            while ((pos = line.find(',')) != string::npos) {
                l.push_back(stoi(line.substr(0, pos)));
                line.erase(0, pos + 1);
            }
            l.push_back(stoi(line));
            memset(dp, -1, sizeof dp);
            ll res = rec(0, 0, 0, s, l);
            ans += res;
        }
        file.close();
    }

    return ans;
}

int main() {
    cout << solve() << endl;
    return 0;
}
