#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, k;
        cin>>n>>m>>k;
        
        vector<int> v;
        for (int i=1 ; i<=k ;i++)
            v.push_back(i);

        if (m%k == 0) {
            vector<int> v1;
            for (int i=2 ; i<=k ; i++) v1.push_back(i);
            v1.push_back(1);

            for (int i=0 ; i<n ; i++) {
                int id = 0;
                for (int j=0 ; j<m ; j++) {
                    if (i&1)
                        cout<<v[id++];
                    else
                        cout<<v1[id++];

                    cout<<" ";

                    id %= k;
                }

                cout<<endl;
            }

        } else {
            int id = 0;
            for (int i=0 ; i<n ; i++) {
                for (int j=0 ; j<m ; j++) {
                    cout<<v[id++]<<" ";
                    id %= k;
                }

                cout<<endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}