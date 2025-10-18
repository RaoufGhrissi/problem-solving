#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

void dfs(int node, int parent, vector<vector<int>> &graph, vector<ll> &vals, vector<ll> &mx, vector<ll> &mi) {
    if (parent == -1) {
        mx[node] = vals[node];
        mi[node] = vals[node];
    } else {
        mx[node] = max(vals[node], vals[node]-mi[parent]);
        mi[node] = min(vals[node], vals[node]-mx[parent]);
    }

    for (int &child:graph[node]) {
        if (child != parent) {
            dfs(child, node, graph, vals, mx, mi);
        }
    }
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<vector<int>> graph(n);
        vector<ll> vals(n);
        vector<ll> mx(n), mi(n);

        for (int i=0 ; i<n ; i++)
            cin>>vals[i];

        for (int i=1 ; i<n ; i++) {
            int x, y;
            cin>>x>>y;
            x--;
            y--;

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        dfs(0, -1, graph, vals, mx, mi);

        for (int i=0 ; i<n ; i++) {
            cout<<mx[i]<<" ";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}