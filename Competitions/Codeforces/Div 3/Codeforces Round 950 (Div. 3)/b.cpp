#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, ll>
#define inf 1e18

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        int ans = 0;
        int id = 1;
        for (int i=2 ; i<=n ; i++) {
            int x = i;
            int res = 0;
            while(x<=n) {
                res += x;
                x += i;
            }

            if (res > ans) {
                ans = res;
                id = i;
            }
        }

        cout<<id<<endl;
    }
}

int main() {
    solve();
    return 0;
}