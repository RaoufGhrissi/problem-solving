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

// minimizi akther ma tnajem combinations 
bool check(ll n, ll deals) {
    ll d = pow(3, 19);

    for (int i=19 ; i>-1 ; i--) {
        if (n==0 || deals == 0) break;
        
        ll q = min(deals, n / d);
        deals -= q;
        n -= d*q;
        d /= 3;
    }

    return n == 0;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        ll n, k;
        cin>>n>>k;

        ll ans = 0;
        ll d = pow(3, 18);

        vector<pp> v;
        int kk=k;

        for (int i=18 ; i>-1 ; i--) {
            ll q = min(k, n / d);

            n -= d*q;
            d /= 3;
            k -= q;

            v.push_back({i, q});
        }

        if (n > 0) {
            cout<<-1<<endl;
            continue;
        }

        int m = v.size();

        for (int i=0 ; i<m ; i++) {
            int x = v[i].first;

            if (i+1<m) {
                int used = v[i].second;
                int have = k&1 ? k-1 : k;

                int toUse = min(have/2, used);
                v[i].second -= toUse;       
                v[i+1].second += 3*toUse;
                k -= toUse * 2;
            }

            ans += v[i].second * (pow(3, x+1) + x * pow(3, x-1));
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}