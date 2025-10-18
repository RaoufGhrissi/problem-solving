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

ll cnt(int k, vector<int> &v, int l, int r) {
    int n = v.size();
    ll ans = 0;
    map<int, int> occ;
    int j = 0;

    for (int i=0 ; i<n ; i++) {
        while(j<n && occ.size() < k) {               
            occ[v[j]]++;
            j++;
        }

        int L = j-i;
        int R = n-1-i+1;

        int sz = occ.size();

        occ[v[i]]--;
        if (occ[v[i]] == 0) {
            occ.erase(v[i]);
        }

        if (sz < k || R < l || r < L) continue;

        int rangeL = max(L, l);
        int rangeR = min(R, r);

        ans += rangeR - rangeL + 1;
    }

    return ans;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, k, l, r;
        cin>>n>>k>>l>>r;

        vector<int> v(n);

        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
        }
        
        cout<<cnt(k, v, l, r) - cnt(k+1, v, l, r)<<endl;    
    }
}

int main() {
    solve();
    return 0;
}