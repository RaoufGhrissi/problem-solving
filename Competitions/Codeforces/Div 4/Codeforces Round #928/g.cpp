#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

const int N = 1e5;
int dp[N][3];

//0: silence
//1: party
//2: neutre

void dfs(int u, int p, vector<vector<int>> &graph, string& s) {
    dp[u][0] = 1e9;
    dp[u][1] = 1e9;
    dp[u][2] = 1e9;
    for (auto &child:graph[u]) {
        if (child == p) continue;
        dfs(child, u, graph, s);
    }

    if (s[u] == 'S') {
        dp[u][0] = 0;
        for (auto &child:graph[u]) {
            if (child == p) continue;
            dp[u][0] += min({dp[child][2], dp[child][0], dp[child][1] + 1});
        }
    }

    if (s[u] == 'C') {
        dp[u][0] = 0;
        dp[u][1] = 0;
        dp[u][2] = 0;
        for (auto &child:graph[u]) {
            if (child == p) continue;
            dp[u][0] += min({dp[child][2], dp[child][0], dp[child][1] + 1});
            dp[u][1] += min({dp[child][2], dp[child][0] + 1, dp[child][1]});
            dp[u][2] += min({dp[child][2], dp[child][0] + 1, dp[child][1] + 1});
        }
    }

    if (s[u] == 'P') {
        dp[u][1] = 0;
        dp[u][0] = 1e9;
        dp[u][2] = 1e9;
        for (auto &child:graph[u]) {
            if (child == p) continue;
            dp[u][1] += min({dp[child][2], 1 + dp[child][0], dp[child][1]});
        }
    }
}


void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<vector<int>> graph(n);
        for (int i=1 ; i<n ; i++) {
            int x;
            cin>>x;
            x--;
            graph[i].push_back(x);
            graph[x].push_back(i);
        }

        string s;
        cin>>s;
        bool found = 0;
        for (int i=0 ; i<n ; i++) {
            if (s[i] == 'S') {
                dfs(i, -1, graph, s);
                cout << dp[i][0]<< endl;
                found = 1;
                break;
            }
        }

        if (!found)
            cout<<0<<endl;
    }
}

int main() {
    solve();
    return 0;
}