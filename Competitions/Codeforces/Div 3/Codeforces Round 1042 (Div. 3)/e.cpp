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

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
        }

        for (int i=0 ; i<n ; i++) {
            cin>>b[i];
        }

        bool ok = 1;
        int start = 0;

        while (start < n) {
            if (a[start] == b[start]) {
                start++;
                continue;
            }

            int r = start+1;
            int cum = a[start];
            while(r<n && cum != b[start]) {
                cum ^= a[r];
                r++;
            }

            if (cum != b[start]) {
                ok = 0;
                break;
            }

            int prev = a[start];
            for (int i=start+1 ; i<r-1 ; i++) {
                int curr = cum^prev;

                if (curr != b[i]) {
                    ok = 0;
                    break;
                }

                prev ^= a[i];
            }

            if (!ok)
                break;

            start = r-1;
        }

        if (ok) yes();
        else no();
    }
}

int main() {
    solve();
    return 0;
}