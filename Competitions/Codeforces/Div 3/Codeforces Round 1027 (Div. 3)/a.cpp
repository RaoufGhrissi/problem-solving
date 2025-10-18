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
        string s;
        cin>>s;

        int res = stoi(s);
        int x = sqrt(res);

        if (x*x == res) {
            cout<<x<<" "<<0<<endl;
        } else {
            cout<<-1<<endl;
        }

        
    }
}

int main() {
    solve();
    return 0;
}