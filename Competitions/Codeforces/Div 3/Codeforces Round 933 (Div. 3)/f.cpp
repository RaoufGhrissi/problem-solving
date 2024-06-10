#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
#define inf 1e18

using namespace std;

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, m, k;
        cin>>n>>m>>k;
        vector<ll> p(n);
        vector<ll> modules(m);
        vector<ll> functions(k);

        for (int i=0; i<n ; i++)
            cin>>p[i];

        for (int i=0; i<m ; i++)
            cin>>modules[i];

        for (int i=0; i<k ; i++)
            cin>>functions[i];

        priority_queue<vector<ll>> gaps;
        sort(p.begin(), p.end());

        for (int i=0; i<n ; i++){
            if (i) {
                gaps.push({p[i]-p[i-1], p[i-1], p[i]});
            }
        }

        vector<ll> x = gaps.top();
        gaps.pop();

        ll s = x[1];
        ll e = x[2];
        ll gap = x[0];
        int mid = (s+e)/2;
        sort(modules.begin(), modules.end());
        sort(functions.begin(), functions.end());

        int i = modules.size() - 1;
        int j = 0;
        int sm = modules[i] + functions[j];

        while(i>-1 && j<functions.size()) {
            gap = min(gap, max(sm-s, e-sm));
            if (sm<mid) {
                sm = functions[++j] + modules[i];
            } else {
                sm = functions[j] + modules[--i];
            }
        }

        if (gaps.empty())
            cout<<gap<<endl;
        else
            cout<<max(gap, gaps.top()[0])<<endl;
    }
}

int main() {
    solve();
    return 0;
}