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
        ll n, k;
        cin>>n>>k;

        vector<int> v(n);

        for (int i=0 ; i<n ; i++) cin>>v[i];

        int i = 0;
        int j = n-1;

        ll removed = 0;
        while(k>0) {
            if (i == j) {
                ll needed = v[i];
                if (k<needed) break;

                removed++;
                break;
            }

            if (v[i] <= v[j]) {
                ll needed = 2*v[i] - 1;
                if (needed > k) break;

                k -= needed;
                v[j] -= v[i];
                removed++;

                if (removed == n) break;
                
                if (!k)
                    break;   

                v[i] = 0;
                i++;
                
                k--;
                if (!v[j]) {
                    j--;
                    removed++;
                }
            } else {
                ll needed = 2*v[j];
                if (needed > k) break;

                k -= needed;
                v[i] -= v[j];

                v[j] = 0;
                j--;
                removed++;
            }

            if (removed == n) break;
        }

        cout<<removed<<endl;
    }
}

int main() {
    solve();
    return 0;
}