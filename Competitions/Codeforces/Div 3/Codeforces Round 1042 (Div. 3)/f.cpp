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

        string s1, s2;
        cin>>s1;
        cin>>s2;

        vector<ll> ones1(n), ones2(n);

        for (int i=0 ; i<n ; i++) {
            ones1[i] = s1[i] - '0';
            ones2[i] = s2[i] - '0';

            if (i) {
                ones1[i] += ones1[i-1];
                ones2[i] += ones2[i-1];
            }
        }

        vector<vector<ll>> v;

        for (int i=0 ; i<n ; i++) {
            int tot = i+1;
            int zeros = tot-ones2[i];
            int diff = ones2[i] - zeros;
            v.push_back({diff, ones2[i], zeros});
        }

        sort(v.begin(), v.end());

        for (int i=1 ; i<n ; i++) {
            v[i][1] += v[i-1][1];
            v[i][2] += v[i-1][2];
        }

        ll ans = 0;

        for (int i=0 ; i<n ; i++) {
            int tot = i+1;
            int zeros = tot-ones1[i];
            int diff = zeros - ones1[i];

            int l = lower_bound(v.begin(), v.end(), vector<int>{diff, 0, 0}) - v.begin();

            int cnt = n-l;

            if (cnt > 0) {
                ll cum = v[n-1][2];
                if (l) {
                    cum -= v[l-1][2];
                }

                ans += cnt*zeros + cum;
            }

            if (l) {
                ll cum = v[l-1][1];
                ans += l*ones1[i] + cum;
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}