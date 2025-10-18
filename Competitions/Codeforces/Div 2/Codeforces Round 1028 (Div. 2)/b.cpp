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

        int op = 0;
        int cnt = 0;

        for (char &c:s) {
            op += c == '(';
            op -= c == ')';

            cnt += op == 0;
        }

        if (cnt == 1)
            no();
        else
            yes();   
    }
}

int main() {        
    solve();
    return 0;
}