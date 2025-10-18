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
        ll n;
        cin>>n;
        ll pow = 10;

        set<ll> ans;

        while((1 + pow) <= n) {
            if ((n%(1+pow)) == 0) {
                ans.insert(n/(1+pow));
            }

            if (pow <= 1e17)
                pow *= 10;
        }

        cout<<ans.size()<<endl;
        for (auto &x:ans)
            cout<<x<<" ";
        
        if (!ans.empty())
            cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}