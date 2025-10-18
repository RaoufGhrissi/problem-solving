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

ll compute(vector<ll> &v, vector<ll> &cum, int pos, int l, int r) {
    ll cnt = pos-l;
    ll ans = cnt*v[pos];

    ll left = 0;
    if (pos)
        left = cum[pos-1];
    if (l)
        left -= cum[l-1];

    ans -= left;

    cnt = r-pos;
    ll right = (cum[r] - cum[pos]) - cnt*v[pos];

    return ans + right;
}

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<ll> a(n);

        for (int i=0 ; i<n ; i++)
            cin>>a[i];

        if (n==1) {
            cout<<1<<endl;
            continue;
        }

        sort(a.begin(), a.end());

        vector<ll> cum = a;
        for (int i=1 ; i<n ; i++)
            cum[i] += cum[i-1];

        int diff = n-k;

        int l, r;
        int ml = (diff-1)/2;
        int mr = (k+(n-1))/2;

        if (!(diff&1)) {
            int ml2 = ml+1;

            ll c1 = compute(a, cum, ml, 0, diff-1);
            ll c2 = compute(a, cum, ml2, 0, diff-1);

            if (c1 <= c2) {
                l = ml;
            } else {
                l = ml2;
            }

            int mr2 = mr+1;

            c1 = compute(a, cum, mr, 0, diff-1);
            c2 = compute(a, cum, mr2, 0, diff-1);

            if (c1 <= c2) {
                r = mr2;
            } else {
                r = mr;
            }

            cout<<a[r]-a[l]+1;
        } else {
            cout<<a[mr]-a[ml]+1;
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}