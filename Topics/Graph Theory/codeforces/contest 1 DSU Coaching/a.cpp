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

class Dsu {
    public:
        int const static N = 1e5 + 1;
        int parent[N];
        int rank[N];
        int minn[N];
        int n;

        Dsu(int _n, vector<int> &v) {
            n = _n;
            for (int i=0 ; i<n ; i++) {
                parent[i] = i;
                rank[i] = 1;
                minn[i] = v[i]; // min fil compknenet eli parent mte3ou i
            }
        }

        int find(int i) {
            if (parent[i] != i)
                return parent[i] = find(parent[i]);

            return i;
        }

        void unionn(int a, int b) {
            int p1 = find(a);
            int p2 = find(b);

            if (p1 == p2) return;

            if (rank[p1] < rank[p2])
                swap(p1, p2);
            
            minn[p1] = min(minn[p1], minn[p2]);
            parent[p2] = p1;
            rank[p1] += rank[p2];
            rank[p2] = 0;
        }
};

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    //cin>>t;
    t = 1;

    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<int> v(n);
        for (int i=0 ; i<n ; i++)
            cin>>v[i];
        
        Dsu dsu = Dsu(n, v);

        while(m--) {
            int x, y;
            cin>>x>>y;
            x--;
            y--;

            dsu.unionn(x, y);
        }
        
        set<int> parents;
        ll ans = 0;
        for (int i=0 ; i<n ; i++) {
            int p = dsu.find(i);
            if (parents.count(p)) continue;
            parents.insert(p);
            ans += dsu.minn[p];
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}