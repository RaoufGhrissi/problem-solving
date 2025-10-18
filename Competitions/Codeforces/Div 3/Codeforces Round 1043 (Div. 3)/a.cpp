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
        string a, b, c;

        cin>>n;
        cin>>a;

        cin>>n;
        cin>>b;
        cin>>c;

        string a1 = "";
        string a2 = "";

        for (int i=0 ; i<n ; i++) {
            if (c[i] == 'V')
                a1 += b[i];
            else
                a2 += b[i];
        }

        reverse(a1.begin(), a1.end());

        a1 += a + a2;

        cout<<a1<<endl;
        
    }
}

int main() {
    solve();
    return 0;
}