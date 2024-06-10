#include <bits/stdc++.h>

using namespace std;


void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    int const N = 2*1e5 + 1;
    int memo[N];
    memo[0] = 0;
    for (int i=1 ; i<N ; i++) {
        memo[i] = 0;
        int m = i;
        while(m) {
            memo[i] += m%10;
            m /= 10;
        }

        memo[i] += memo[i-1];
    }

    while(t--) {
        int n;
        cin>>n;
        cout<<memo[n]<<endl;
    }
}

int main() {
    solve();
    return 0;
}