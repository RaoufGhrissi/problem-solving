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

        vector<int> v(n), cum(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            cum[i] = v[i];

            if (i)
                cum[i] += cum[i-1];
        }

        bool ok = 0;

        for (int l=0 ; l<n-2 ; l++) {
            if (ok)
                break;

            for (int r=l+1 ; r<n-1 ; r++) {
                int s1 = cum[l] % 3;
                int s2 = (cum[r] - cum[l]) % 3;
                int s3 = (cum[n-1] - cum[r]) % 3;

                if (s1 == s2 && s2==s3) {
                    ok = 1;
                    cout<<l+1<<" "<<r+1<<endl;
                    break;
                }

                if (s1 != s2 && s1 != s3 && s2 != s3) {
                    ok = 1;
                    cout<<l+1<<" "<<r+1<<endl;
                    break;
                }
            }
        }

        if (!ok) {
            cout<<0<<" "<<0<<endl;
        }
    }
}

int main() {
    solve();
    return 0;
}