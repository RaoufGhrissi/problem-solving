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

int mod = 998244353;

ll dp[5000][5000];

ll rec(int i, int j, vector<int> &a, vector<int> &chaine) {
    if (i == a.size()) {
        return j == chaine.size();
    }

    ll ans = dp[i][j];
    if (ans != -1) {
        return ans;
    }

    ans = rec(i+1, j, a, chaine); // mathezouch

    if ((j<chaine.size()) && (a[i] == chaine[j])) {
        ans = (ans + rec(i+1, j+1, a, chaine)) % mod; // thezou
    } else if (j && (a[i] <= chaine[j-1])) {
        ans = (ans + rec(i+1, j, a, chaine)) % mod; // thezou
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
        int n;
        cin>>n;

        vector<int> a(n);
        vector<int> comp;

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
        }

        comp.push_back(a[0]);
        for (int i=1 ; i<n ; i++) {
            if (a[i] != a[i-1])
                comp.push_back(a[i]);
        }
        
        int sz = comp.size();
        set<int> ids = {0, sz-1};
        int mx = comp[0];

        for (int i=1 ; i<sz ; i++) {
            if (comp[i] > mx) {
                mx = comp[i];
                ids.insert(i);
            }
        }

        mx = comp[sz-1];
        for (int i=sz-2 ; i>-1 ; i--) {
            if (comp[i] > mx) {
                mx = comp[i];
                ids.insert(i);
            }
        }

        vector<int> chaine;
        for (auto &id:ids) {
            if (chaine.empty() || comp[id] != chaine[chaine.size()-1])
                chaine.push_back(comp[id]);
        }

        
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<sz ; j++) {
                dp[i][j] = -1;
            }
        }

        cout<<rec(0, 0, a, chaine)<<endl;
    }
}

int main() {
    solve();
    return 0;
}