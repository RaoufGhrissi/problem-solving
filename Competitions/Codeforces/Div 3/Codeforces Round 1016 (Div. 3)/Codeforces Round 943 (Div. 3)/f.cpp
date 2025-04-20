#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    string b;

    while(t--) {
        int n, m;
        cin>>n>>m;

        vector<string> a(n);
        vector<bool> exist(n, 0);

        int mxMatch = 0;

        for (int i=0 ; i<n ; i++)
            cin>>a[i];

        while(m--) {
            int cnt = 0;
            for (int i=0 ; i<n ; i++) {
                cin>>b;

                if (b.size() != a[i].size()) continue;

                bool match = 1;
                for (int pos=0 ; pos<b.size() ; pos++) {
                    if (a[i][pos] != b[pos]) match = 0;
                }

                if (match)
                    exist[i] = 1; 
                
                cnt += match;
            }

            mxMatch = max(mxMatch, cnt);
        }

        int x = *min_element(exist.begin(), exist.end());

        if (!x) {
            cout<<"-1"; 
        } else {
            cout<<n + (n-mxMatch)*2;
        }

        
        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}