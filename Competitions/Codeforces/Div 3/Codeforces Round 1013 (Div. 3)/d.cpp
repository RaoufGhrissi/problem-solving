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
        int n,m,k;

        cin>>n>>m>>k;

        int s = 1;
        int e = m;

        while(s<e) {
            ll mid = (s+e)/2;

            ll benchs = m/(mid+1);
            ll rest = m - benchs*(mid+1);
            ll kk = (rest + benchs*mid)*n;

            if (kk >= k) {
                e = mid;
            } else {
                s = mid+1;
            }
        }

        cout<<s<<endl;
    }
}

int main() {
    solve();
    return 0;
}