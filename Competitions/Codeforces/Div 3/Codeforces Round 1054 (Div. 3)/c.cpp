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
        int n, k;
        cin>>n>>k;
        
        set<int> st;

        int ks = 0;
        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;
            ks += x==k;
            st.insert(x);
        }

        int missing = 0;
        for (int i=0 ; i<k ; i++) {
            if (!st.count(i))
                missing++;
        }

        cout<<max(missing, ks)<<endl;
    }
}

int main() {
    solve();
    return 0;
}