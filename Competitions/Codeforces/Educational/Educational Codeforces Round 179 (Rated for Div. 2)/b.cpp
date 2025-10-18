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

int fib[11];

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    fib[1] = 1;
    fib[2] = 2;

    for (int i=3 ; i<11 ; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    while(t--) {
        int n, m;
        cin>>n>>m;

        string ans = "";

        for (int i=0 ; i<m ; i++) {
            int w, l, h;
            cin>>w>>l>>h;

            bool ok = 1;
            for (int i=n ; i>0 ; i--) {
                if (fib[i]<=h && fib[i]<=l && fib[i]<=w) {
                    int r1 = l-fib[i];
                    int r2 = w-fib[i];

                    if (i>0) {
                        int j = fib[i-1];
                        if (j<=r1 || j<=r2) {
                            break;
                        }
                    }

                    h -= fib[i];
                    l = fib[i];
                    w = fib[i];
                } else {
                    ok = 0;
                    break;
                }
            }

            if (ok) ans += "1";
            else ans += "0";
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}