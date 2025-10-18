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
        string s;

        cin>>n>>s;

        int cnt = 0;
        for (int i=0 ; i<n ; i++)
            cnt += s[i] == '1';

        int tot = 0;
        for (int i=0 ; i<n ; i++) {
            if (s[i] == '1')
                tot += cnt-1;
            else
                tot += cnt+1; 
        }

        cout<<tot<<endl;
    }
}

int main() {
    solve();
    return 0;
}