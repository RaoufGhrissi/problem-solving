#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n, a, b;
        cin>>n>>a>>b;

        int mid = n/2;
        int rest = n%2;

        cout<<min(2*a, b)*mid + a*rest<<endl;
    }
}

int main() {
    solve();
    return 0;
}