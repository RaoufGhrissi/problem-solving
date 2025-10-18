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

        map<int,int> mp;

        for (int i=0 ; i<n ; i++) {
            int x;
            cin>>x;
            mp[x]++;
        }
        
        int cnt = 0;
        int prev = -1;
        for (auto &a:mp) {
            if (prev == -1) {
                cnt++;
                prev = a.first;
            } else {
                if (prev+1 < a.first) {
                    cnt++;
                    prev = a.first;
                }
            }
        }   

        cout<<cnt<<endl;
        
    }
}

int main() {
    solve();
    return 0;
}