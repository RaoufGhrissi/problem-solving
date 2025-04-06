#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
#define mod 998244353
using namespace std;

ll dp[300005];
ll parent[300005];
vector<int> tree[300005];
vector<int> nodes_per_level[300005];

void dfs(int node, int p = -1, int l = 0) {
    nodes_per_level[l].push_back(node);
    for (int child : tree[node]) {
        if (child != p) {
            dfs(child, node, l+1);
        }
    }
}

ll rec(int node, int p = -1, int l = 0) {
    if (dp[node] != -1) return dp[node];

    dp[node] = 1;
    for (int child : nodes_per_level[l+1]) {
        if (child == p) continue;
        if (l && parent[child] == node) continue;

        dp[node] = (dp[node] + rec(child, node, l+1)%mod)%mod;
    }

    return dp[node];
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;

        for (int i=0 ; i<=n ; i++) tree[i].clear();
        for (int i=0 ; i<=n ; i++) nodes_per_level[i].clear();
        memset(dp, -1, sizeof(dp));

        for (int i=2 ; i<=n ; i++) {
            int x;
            cin>>x;
            tree[x].push_back(i);
            parent[i] = x;
        }

        dfs(1);
        cout<<rec(1)<<endl;
    }
}

int main() {
    solve();
    return 0;
}