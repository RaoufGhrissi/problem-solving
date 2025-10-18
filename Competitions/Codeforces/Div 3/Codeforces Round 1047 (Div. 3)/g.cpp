#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pp pair<int, int>

class Graph {
    public:
        vector<vector<int>> parents;
        vector<int> out;
        int n;
        vector<bool> dp1, dp2;

    Graph(int _n) {
        n = _n;
        dp1.resize(n);
        dp2.resize(n);
        parents.resize(n);
        out.resize(n);

        for (int i=0 ; i<n ; i++) {
            dp1[i] = 1;
            dp2[i] = 0;
            out[i] = 0;
        }
    }

    void add(int a, int b) {
        parents[b].push_back(a);
        out[a]++;
    }

    void update(int node) {
        queue<pp> q;
        if (dp1[node] == 1) { // kont nerbah => bech nwali nakhser
            q.push({node, 0});
        }

        if (dp2[node] == 0) { // ken khaser => bech ywali rebah
            dp2[node] = 1;
            q.push({node, dp2[node]});
        }

        while(!q.empty()) {
            int i = q.front().first;
            int howaYerbah = q.front().second;

            q.pop();

            if (howaYerbah) {
                for (int &p:parents[i]) {
                    out[p]--;
                    if (out[p] == 0) { // maach fama wehed ynajem youselou rebah
                        q.push({p, 0});
                    }
                }
            } else {
                if (dp1[i] == 0)
                    continue;
                
                dp1[i] = 0;

                for (int &p:parents[i]) {
                    if (dp2[p] == 0) {
                        dp2[p] = 1;
                        q.push({p, dp2[p]});
                    }
                }
            }
        }
    }

    bool get(int node) {
        return dp1[node];
    }
};

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, m, q;
        cin>>n>>m>>q;
        Graph g = Graph(n+1);

        while(m--) {
            int x, y;
            cin>>x>>y;

            g.add(x, y);
        }

        while(q--) {
            int _type, node;
            cin>>_type>>node;

            if (_type == 1) {
                g.update(node);
            } else {
                if (g.get(node)) yes();
                else no();
            }
        }
    }
}

int main() {
    solve();
    return 0;
}