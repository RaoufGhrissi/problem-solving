#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
#define mod 998244353
using namespace std;

ll dp[300005];
ll sm[300005];
ll parent[300005];
vector<int> tree[300005];

ll bfs() {
    queue<pp> q;
    q.push({0, 1});

    ll ans = 0;
    dp[1] = 1;

    while(!q.empty()) {
        pp front = q.front();
        q.pop();

        int level = front.first;
        int node = front.second;

        if (node != 1) {
            dp[node] = parent[node] == 1 ? dp[1] : (sm[level-1] - dp[parent[node]] + mod)%mod;
        }

        ans = (ans + dp[node])%mod;
        sm[level] = (sm[level] + dp[node])%mod;
        
        for (int &child:tree[node]) {
            q.push({level+1, child});
        }
    }

    return ans;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;

        for (int i=0 ; i<=n ; i++) tree[i].clear();
        memset(dp, -1, sizeof(dp));
        memset(sm, 0, sizeof(sm));

        for (int i=2 ; i<=n ; i++) {
            int x;
            cin>>x;
            tree[x].push_back(i);
            parent[i] = x;
        }

        cout<<bfs()<<endl;
    }
}

int main() {
    solve();
    return 0;
}