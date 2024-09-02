#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

set<int> st;

int cnt = 0;

bool dfs(int root, int parent, vector<bool> &should, vector<vector<int>> &graph) {
    should[root] = st.count(root) > 0;

    for (auto &child:graph[root]) {
        if (child != parent) {
            bool ss = dfs(child, root, should, graph);
            should[root] = should[root] || ss;
        }
    }
    
    cnt += should[root];
    return should[root];
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t = 1;
    //cin>>t;

    while(t--) {
        int n, k;

        cin>>n>>k;

        vector<vector<int>> graph(n+1);
        for (int i=0 ; i<n-1 ; i++) {
            int a, b;
            cin>>a>>b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        while(k--) {
            int x;
            cin>>x;

            st.insert(x);
        }
        
        vector<bool> should(n+1, 0);
        dfs(*st.begin(), -1, should, graph);

        cout<<cnt;
    }
}

int main() {
    solve();
    return 0;
}