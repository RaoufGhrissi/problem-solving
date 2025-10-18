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
        int const static N = 1e5 + 1;
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

            if (p1 == p2) return;

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
        int n;
        cin>>n;

        vector<pp> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i].first>>v[i].second;
        }

        Dsu dsu = Dsu(n);

        for (int i=0 ; i<n ; i++) {
            for (int j=i+1 ; j<n ; j++) {
                int x1 = v[i].first;
                int y1 = v[i].second;

                int x2 = v[j].first;
                int y2 = v[j].second;

                if (x1 == x2 || y1 == y2) {
                    dsu.unionn(i, j);
                }
            }
        }

        set<int> parents;
        for (int i=0 ; i<n ; i++) {
            parents.insert(dsu.find(i));
        }
        
        cout<<parents.size() - 1<<endl;
    }
}

int main() {
    solve();
    return 0;
}