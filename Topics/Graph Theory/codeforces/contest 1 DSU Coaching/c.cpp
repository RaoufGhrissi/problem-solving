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
        int n, m;
        cin>>n>>m;

        vector<vector<int>> languageEmployees(m);
        vector<int> noLanguage; // eli mayahki hatchay
        int languageWithSpeakers = 0;

        for (int i=0 ; i<n ; i++) {
            int k;
            cin>>k;

            if (k == 0) {
                noLanguage.push_back(i);
                continue;
            }

            while(k--) {
                int x;
                cin>>x;
                x--;

                languageWithSpeakers = x;
                languageEmployees[x].push_back(i);
            }
        }

        int ans = 0;

        for (int &e:noLanguage) {
            languageEmployees[languageWithSpeakers].push_back(e);
            ans++;
        }

        Dsu dsu = Dsu(n);

        for (int i=0 ; i<m ; i++) {
            for (int j=1 ; j<languageEmployees[i].size() ; j++) {
                dsu.unionn(languageEmployees[i][j], languageEmployees[i][j-1]);
            }
        }
        
        set<int> parents;
        for (int i=0 ; i<n ; i++) {
            parents.insert(dsu.find(i));
        }

        cout<<ans + parents.size()-1<<endl;
    }
}

int main() {
    solve();
    return 0;
}