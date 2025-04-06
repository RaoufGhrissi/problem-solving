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
        int n;
        cin>>n;

        int q = n/15;
        int r = n%15;        

        cout<<q * 3 + min(3, r+1)<<endl; 
    }
}

int main() {
    solve();
    return 0;
}