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

        map<ll, ll> occ;
        vector<ll> res;

        ll ans = 0;
        for (int i=0 ; i<n ; i++) {
            ll a;
            cin>>a;

            occ[a]++;
        }

        ll cnt = 0;

        for (auto &a:occ) {
            ll eachSide = a.second / 2;
            ll tot = eachSide*2;
            occ[a.first] -= tot;
            ans += a.first*tot;
            cnt += tot;

            if (occ[a.first] > 0) {
                res.push_back(a.first);
            }
        }

        if (ans == 0) {
            cout<<ans<<endl;
            continue;
        }

        sort(res.begin(), res.end());

        // try to take 2
        bool taken = 0;
        int m = res.size();
        for (int i=m-1 ; i>0 ; i--) {
            if (ans + res[i-1] > res[i]) {
                ans += res[i] + res[i-1];
                cnt += 2;
                taken = 1;
                break;
            }
        }

        if (taken) {
            cout<<ans<<endl;
            continue;
        }

        // try to take 1
        for (int i=m-1 ; i>-1 ; i--) {
            if (ans > res[i]) {
                ans += res[i];
                cnt++;
                break;
            }
        }

        if (cnt == 2) {
            cout<<0<<endl;
            continue;
        }

        cout<<ans<<endl;


    }
}

int main() {
    solve();
    return 0;
}