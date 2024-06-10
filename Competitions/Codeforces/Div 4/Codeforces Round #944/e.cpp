#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n,k,q;
        cin>>n>>k>>q;

        vector<int> a(k+1), b(k+1);
        a[0] = 0;
        b[0] = 0;

        for (int i=1 ; i<=k ; i++) cin>>a[i];
        for (int i=1 ; i<=k ; i++) cin>>b[i];

        while(q--) {
            int d;
            cin>>d;

            if (d==n) {
                cout<<b[k]<<" ";
                continue;
            }

            int pos = lower_bound(a.begin(), a.end(), d) - a.begin();

            if (a[pos] > d)
                pos--;

            int x = a[pos+1]-a[pos];
            int tt = b[pos+1]-b[pos];
            int dist = d-a[pos];

            cout<<b[pos] + dist*1ll*tt/x<<" ";
            int ww = 0;
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}