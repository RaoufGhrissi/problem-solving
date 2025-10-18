#include <bits/stdc++.h>
#define  ll long long
#define pp pair<int,int>
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
        ll k, x;
        cin>>k>>x;
        
        ll mid = 1ll<<k, sm = 1ll<<(k+1);

        vector<int> res;

        while(mid != x) {
            if (x < mid) {
                x *= 2;
                res.push_back(1);
            } else {
                x = sm - (sm-x)*2;
                res.push_back(2);                
            }
        }

        int n = res.size();
        cout<<n<<endl;

        for (int i=n-1 ; i>-1 ; i--)
            cout<<res[i]<<" ";

        cout<<endl;

    }
}

int main() {
    solve();
    return 0;
}