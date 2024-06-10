#include <bits/stdc++.h>
#define pp pair<int,int>
#define  ll long long
#define inf 1e18
using namespace std;

ll div_ceil(ll a, ll b) {
    return a%b ? a/b + 1 : a/b;
}

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        ll n; 
        cin>>n;

        string s;
        cin>>s;

        int ones = count(s.begin(), s.end(), '1');
        int zeros = 0;
        
        int ans = 0;
        int diff = 1e9;
        int mid1 = n/2;
        int mid2 = n&1 ? div_ceil(n, 2) : -1;
        for (int i=0 ; i<=n ; i++) {
            if (zeros >= div_ceil(i, 2) && ones >= div_ceil(n-i, 2)) {
                int d = abs(mid1 - i);
                if (mid2 != -1)
                    d = min(d, abs(mid2 - i));

                if (d < diff) {
                    diff = d;
                    ans = i;
                }
            }

            if (i==n) {
                break;
            }

            ones -= s[i]-'0';
            zeros += 1-(s[i]-'0');
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}