#include <bits/stdc++.h>
#define  ll long long
#define pp pair<ll, ll>
#define inf 1e18

using namespace std;

void solve() {
    //freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        string a,b;
        cin>>a>>b;

        swap(a[0], b[0]);

        cout<<a<<" "<<b<<endl;
    }
}

int main() {
    solve();
    return 0;
}