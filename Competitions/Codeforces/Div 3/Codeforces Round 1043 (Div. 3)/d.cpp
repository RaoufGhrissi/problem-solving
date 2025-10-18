#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>

using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

ll getSum(ll n) {
    return (n+1)*n/2;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    vector<ll> v = {9};

    int i = 0;
    ll _pow = 10;
    ll digits = 1;
    ll nums = 9;
    while(v[i] < 1e15) {
        digits++;
        nums *= 10;
        v.push_back(v[i] + nums*digits);
        i++;
        _pow *= 10;
    }

    vector<ll> sum = {45};
    _pow = 10;

    for (int i=1 ; i<15 ; i++) {
        // i=0 => sum(10 power 1 - 1 = 9)
        // i=1 => sum(10 power 2 - 1)
        // i=14 => sum(10 power 15 - 1)
        sum.push_back(sum[i-1]*10 + _pow * 45);
        _pow *= 10;
    }

    int n = v.size();

    while(t--) {
        ll k;
        cin>>k;

        int p = 0;
        while(k > v[p]) {
            p++;
        }   

        ll x = 0;
        ll kk = k;
        if (p) {
            x = pow(10, p) - 1;
            kk -= v[p-1];
        }

        ll d = p+1;
        ll q = kk/d;
        ll r = kk%d;
        x += q;

        string s;
        ll ans = 0;
        
        if (r > 0) {
            s = to_string(x+1);
            for (int i=0 ; i<r ; i++) {
                ans += s[i]-'0';
            }
        }

        ll sm = 0;

        s = to_string(x);
        int m = s.size()-1;
        if (m > 0) {
            ans += sum[m-1];
        }

        _pow = pow(10, m);  
        digits = m-1;
        for (int i=0 ; i<=m ; i++) {    
            ll dd = s[i] - '0';
            if (dd) {
                ll prev = i==0 ? dd-1 : dd;
                sm = digits > -1 ? sum[digits] : 0;
                ans += prev*sm + _pow*getSum(dd-1) + dd*((x%_pow) + 1);
            }

            _pow /= 10;
            digits--;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}