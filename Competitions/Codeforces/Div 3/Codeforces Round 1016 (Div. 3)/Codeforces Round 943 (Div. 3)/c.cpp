#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18            
using namespace std;

bool isPrime(int x) {
    if (x == 2) return 1;
    if (x<2) return 0;
    if (x%2 == 0) return 0;

    for (int i=3 ; i*i<=x ; i++) {
        if (x%i == 0) return 0;
    }

    return 1;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int x, k;
        cin>>x>>k;

        if (k==1) {
            if (isPrime(x)) cout<<"YES";
            else cout<<"NO";
        } else {
            if (x == 1 && k==2) cout<<"YES";
            else cout<<"NO";
        }

        cout<<endl;
    }
}

int main() {
    solve();
    return 0;
}