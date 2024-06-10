#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;
    
    while(t--) {
        int n, k;
        cin>>n>>k;

        int sm = 0;
        int d = 0;
        int r;

        while(sm < n) {
            int tot = n/(1<<d) - n/(1<<(d+1));
            if (sm + tot <= k) {
                sm += tot;
                
                if (sm == k) {
                    r = tot;
                    break;
                }
                d++;
            } else {
                r = k-sm;
                break;
            }
        }

        
        int ans = (2*r-1)*(1<<d);

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}