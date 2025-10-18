#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n,k;
        cin>>n>>k;

        vector<ll> v(n);

        ll tot = 0;
        for (int i=0 ; i<n ; i++) {
            cin>>v[i];
            tot += v[i];
        }

        sort(v.begin(), v.end());
        v[n-1]--;
        sort(v.begin(), v.end());

        if (v[n-1]-v[0] > k) {
            cout<<"Jerry";
        } else {
            if (tot&1) {
                cout<<"Tom";
            } else {
                cout<<"Jerry";
            }
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}