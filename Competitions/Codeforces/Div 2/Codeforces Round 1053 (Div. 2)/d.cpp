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

ll mod = 998244353;

class Cnk {
    public:
        int static const N = 2*1e5 + 1;
        ll fact[N];
        ll invFact[N];

        ll inv(int a) {
            return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
        }

        Cnk() {
            fact[0] = 1;
            for (int i=1 ; i<N ; i++)
                fact[i] = (i * fact[i-1]) % mod;

            invFact[N-1] = inv(fact[N-1]);
            for (int i=N-2 ; i>-1 ; i--)
                invFact[i] = ((i+1) * invFact[i+1]) % mod;      
        }

        ll compute(int n, int k) {
            if (!k)
                return 1;

            if (!n)
                return 0;

            return ((fact[n] * invFact[n-k]) % mod * invFact[k]) % mod;
        }
};

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    Cnk cnk = Cnk();

    while(t--) {
        int n;
        cin>>n;

        vector<int> a(n);
        bool z = 0;

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
            z |= a[i] > 0;
        }

        int mid = n&1 ? n/2 : n/2 - 1;
        int cnt = n&1 ? 1 : 2;
        
        bool ok = 1;
        for (int i=mid+1 ; i<n ; i++) {
            if (a[i] > 0) {
                ok = 0;
                break;
            }
        }

        if (!ok) {
            cout<<0<<endl;
            continue;
        }
        
        ll ans = 1;
        int used = 0;
    
        for (int i=mid ; i>-1 ; i--) {
            int tot = cnt-used;
            if (a[i] > tot) {
                ok = 0;
                break;
            }

            ans = (ans * cnk.compute(tot, a[i])) % mod;
            used += a[i];
            cnt+=2;
        }

        if (!ok || (used < n)) {
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