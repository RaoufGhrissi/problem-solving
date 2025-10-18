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
        int n;
        cin>>n;
        vector<int> odd, even;

        ll ans = 0;

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;

            if (x&1)
                odd.push_back(x);
            else
                even.push_back(x);
        }

        if (odd.empty()) {
            cout<<0<<endl;
            continue;
        }

        sort(odd.begin(), odd.end(), greater<int>());

        for (int &x:even)
            ans += x;

        int m = odd.size();
        int id = m&1 ? m/2 + 1 : m/2;
        
        int i = 0;
        while(i<id) {
            ans += odd[i];
            i++;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}