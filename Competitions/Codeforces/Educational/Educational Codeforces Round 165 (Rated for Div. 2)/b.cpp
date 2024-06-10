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
        int n, k;
        cin>>n>>k;

        vector<int> a(n), b(n);

        for (int i=0 ; i<n ; i++) {
            cin>>a[i];
        }

        for (int i=0 ; i<n ; i++) {
            cin>>b[i];
        }

        int sm = 0;
        int mx = 0;
        int cnt = 0;

        for (int i=0 ; i<n ; i++) {
            if (a[i] >= b[i]) {
                sm += a[i]-b[i];
                mx = max(mx, b[i]);
            }
        }

        for (int i=0 ; i<n ; i++) {
            if (b[i] > mx && cnt < k)
                cnt++;
        }
        

        cout<<sm<<endl;
    }
}

int main() {
    solve();
    return 0;
}