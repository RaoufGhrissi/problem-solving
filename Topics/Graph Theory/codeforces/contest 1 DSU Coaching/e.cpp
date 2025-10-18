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
        bool cycle[N];

        Dsu(int k) {
            n = k;
            for (int i=0 ; i<n ; i++) {
                parent[i] = i;
                rank[i] = 1;
                cycle[i] = 0;
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
                cycle[p1] = 1;
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
    cin>>t;
    //t = 1;

    while(t--) {
        int n;
        cin>>n;

        set<pp> unique;

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;
            x--;
            //khalit edges unique, ysob ken 1, 2  kif tji 2, 1 baed maysobhech
            unique.insert({min(i, x), max(i, x)});
        }

        Dsu dsu = Dsu(n);

        for (auto &p:unique) {
            dsu.unionn(p.first, p.second);
        }

        int cyclic = 0;
        int others = 0;
        set<int> parents;
        
        for (int i=0 ; i<n ; i++) {
            int p = dsu.find(i);

            if (!parents.count(p)) {
                if (dsu.cycle[p])
                    cyclic++;
                else
                    others++;
            } 
            parents.insert(p);
        }

        int mi = cyclic;
        if (others) {
            mi++;
        }

        int mx = cyclic + others;

        cout<<mi<<" "<<mx<<endl;
    }
}

int main() {
    solve();
    return 0;
}