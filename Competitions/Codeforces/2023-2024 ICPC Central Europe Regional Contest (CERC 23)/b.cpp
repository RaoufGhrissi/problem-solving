#include <bits/stdc++.h>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
}

void solve() {
    freopen("a.txt", "r", stdin);

    int n;
    cin>>n;

    string s;
    cin>>s;

    vector<vector<int>> b, g;

    for (int i=0 ; i<n ; i++) {
        int x, y;
        cin>>x>>y;
        if (s[i] == 'B') b.push_back({x, y});
        else g.push_back({x, y});
    }

    double ans = 0;
    int sz = b.size();

    for (int i=0 ; i<sz/2 ; i++) {
        ans += dist(b[i][0], b[i][1], b[sz/2 + i][0], b[sz/2 + i][1]);
    }

    sz = g.size();

    for (int i=0 ; i<sz/2 ; i++) {
        ans += dist(g[i][0], g[i][1], g[sz/2 + i][0], g[sz/2 + i][1]);
    }

    cout<<fixed;
    cout<<setprecision(9)<<ans;
}

int main() {
    solve();
    return 0;
}