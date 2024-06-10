#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

//https://codeforces.com/contest/1969/problem/D

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n, k;
        cin>>n>>k;

        vector<pp> v(n);
        vector<ll> a(n), b(n), cum(n, 0);

        for (int i=0 ; i<n ; i++) cin>>a[i];
        for (int i=0 ; i<n ; i++) cin>>b[i];

        for (int i=0 ; i<n ; i++) {
            v[i] = {b[i], a[i]};
        }

        sort(v.begin(), v.end());

        for (int i=0 ; i<n ; i++) {
            ll diff = v[i].first - v[i].second;
            if (diff > 0) cum[i] = diff;

            if (i) cum[i] += cum[i-1];
        }

        if (!k) {
            cout<<cum[n-1]<<endl;
            continue;

        }

        priority_queue<ll> pq;
        ll ans = 0;
        ll sm = 0;

        for (int i=n-1 ; i>-1 ; i--) {
            sm += v[i].second;
            pq.push(v[i].second);

            if (pq.size() > k) {
                ll t = pq.top();
                pq.pop();
                sm -= t;
            }

            if (pq.size() == k)
                ans = max(ans, (i ? cum[i-1] : 0) - sm);
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}