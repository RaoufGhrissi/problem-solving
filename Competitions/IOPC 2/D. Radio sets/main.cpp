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

void build(vector<vector<int>> &v, int &n, Dsu &dsu) {
        sort(v.begin(), v.end());
        int prevX2 = v[0][1];

        for (int i=1 ; i<n ; i++) {
            int x1 = v[i][0];
            int x2 = v[i][1];

            if (x1 <= prevX2) {
                prevX2 = max(prevX2, x2);
                dsu.unionn(v[i][4], v[i-1][4]);
            } else {
                prevX2 = x2;
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

        vector<vector<int>> v(n, vector<int>(5));

        for (int i=0 ; i<n ; i++) {
            cin>>v[i][0]>>v[i][2]>>v[i][1]>>v[i][3];
            v[i][4] = i;
        }

        Dsu dsu = Dsu(n);

        build(v, n, dsu);
        for (int i=0 ; i<n ; i++) {
            swap(v[i][0], v[i][2]);
            swap(v[i][1], v[i][3]);
        }

        build(v, n, dsu);

        ll ans = 0;
        ll cnt = 0;
        for (int i=0 ; i<n ; i++) {
            if (dsu.rank[i]) {
                cnt++;
                ans += dsu.rank[i]-1;
            }
        }

        cout<<ans + 2*(cnt-1)<<endl;
    }
}

int main() {
    solve();
    return 0;
}