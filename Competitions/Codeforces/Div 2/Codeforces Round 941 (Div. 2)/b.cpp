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
        int n, m;
        cin>>n>>m;

        vector<string> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }

        if (v[0][0] == v[n-1][m-1])
            cout<<"YES"<<endl;
        else {
            // swap 0, 0

            bool find1 = 0;
            for (int col=1 ; col<m ; col++) {
                if (v[0][col] != v[0][0]) find1 = 1;
            }

            bool find2 = 0;
            for (int l=1 ; l<n ; l++) {
                if (v[l][0] != v[0][0]) find2 = 1;
            }

            if (find1 && find2) {
                cout<<"YES"<<endl;
                continue;
            }

            // swap n-1, m-1

            find1 = 0;
            for (int col=0 ; col<m-1 ; col++) {
                if (v[n-1][col] != v[n-1][m-1]) find1 = 1;
            }

            find2 = 0;
            for (int l=0 ; l<n-1 ; l++) {
                if (v[l][m-1] != v[n-1][m-1]) find2 = 1;
            }

            if (find1 && find2) {
                cout<<"YES"<<endl;
            } else {
                cout<<"NO"<<endl;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}