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
        int n,m,l,r;
        cin>>n>>m>>l>>r;

        int diff = n-m;
        while(l<0 && diff>0) {
            l++;
            diff--;
        }

        while(diff>0 && r>0) {
            r--;
            diff--;
        }

        cout<<l<<" "<<r<<endl;
    }
}

int main() {
    solve();
    return 0;
}