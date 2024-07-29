#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, ll>
#define inf 1e18

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, q;
        cin>>n>>q;

        string a, b;
        cin>>a>>b;

        int cumA[n][26];
        int cumB[n][26];

        memset(cumA, 0, sizeof cumA);
        memset(cumB, 0, sizeof cumB);

        for (int i=0 ; i<n ; i++) {
            cumA[i][a[i]-'a'] = 1;
            cumB[i][b[i]-'a'] = 1;
        }

        for (int c=0 ; c<26 ; c++) {
            for (int i=1 ; i<n ; i++) {
                cumA[i][c] += cumA[i-1][c];
                cumB[i][c] += cumB[i-1][c];
            }
        }

        while(q--) {
            int l, r;
            cin>>l>>r;
            l--;
            r--;

            int ans = 0;
            for (int c=0 ; c<26 ; c++) {
                int occA = cumA[r][c];
                int occB = cumB[r][c];

                if (l) {
                    occA -= cumA[l-1][c];
                    occB -= cumB[l-1][c];
                }

                if (occA > occB)
                    ans += occA - occB;
            }

            cout<<ans<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}