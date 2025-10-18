#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, pair<ll,ll>>
#define inf 1e18
using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
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

        vector<pp> v;

        ll mx = 0;
        int mxI, mxJ;

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                ll nl = n-1-j;
                ll nr = n-1-i;
                ll cnt = nl*nr+nl+nr+1;
                ll prev = (i+1)*(j+1);
                ll tot = prev*cnt;

                v.push_back({tot, {i, j}});
                if (tot > mx) {
                    mxI = i;
                    mxJ = j;
                    mx = tot;
                }

                //cout<<tot<<"    ";
            }
            //cout<<endl;
        }

        sort(v.begin(), v.end());

        int val = 0;

        int sz = v.size();
        vector<vector<int>> mat(n, vector<int>(n, -1));
        for (int i=sz-1 ; i>-1 ; i--) {
            int x = v[i].second.first;
            int y = v[i].second.second;

            if (x < mxI || y<mxJ) continue;
            mat[x][y] = val++;
        }

        for (int i=mxI-1 ; i>-1 ; i--) {
            for (int j=mxJ ; j<n; j++) {
                mat[i][j] = val++;
            }
        }

        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (mat[i][j] == -1)
                    mat[i][j] = val++;

                cout<<mat[i][j]<<" ";
            }

            cout<<endl;
        }

    }
}

int main() {
    solve();
    return 0;
}