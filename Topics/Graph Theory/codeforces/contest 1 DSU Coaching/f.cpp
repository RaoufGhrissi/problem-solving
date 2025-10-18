#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e9
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

class Dsu {
    public:
        int const static N = 5*1e5 + 1;
        int parent[N];
        int rank[N];
        int n;

        Dsu(int k) {
            n = k;
            for (int i=0 ; i<n ; i++) {
                parent[i] = i;
                rank[i] = 1;
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

            if (p1 == p2) {
                return;
            }

            if (rank[p1] < rank[p2])
                swap(p1, p2);

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
        int n,m1,m2, x, y;
        cin>>n>>m1>>m2;

        Dsu mocha = Dsu(n);
        Dsu diana = Dsu(n);

        for (int i=0 ; i<m1 ; i++) {
            cin>>x>>y;
            x--;
            y--;
            mocha.unionn(x, y);
        }

        for (int i=0 ; i<m2 ; i++) {
            cin>>x>>y;
            x--;
            y--;
            diana.unionn(x, y);
        }

        vector<pp> ans;
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                int p1 = mocha.find(i);
                int p2 = mocha.find(j);

                if (p1 == p2) continue;

                int dianaP1 = diana.find(i);
                int dianaP2 = diana.find(j);

                if (dianaP1 == dianaP2) continue;

                diana.unionn(i, j);
                mocha.unionn(i, j);
                ans.push_back({i+1, j+1});
            }
        }

        cout<<ans.size()<<endl;
        for (const auto &[f, s]:ans) {
            cout<<f<<" "<<s<<endl;
        }
        
    }
}

int main() {
    solve();
    return 0;
}