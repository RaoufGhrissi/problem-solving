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
        int n,m;
        cin>>n>>m;

        vector<int> v(m);
        for (int i=0 ; i<m ; i++)
            cin>>v[i];

        sort(v.begin(), v.end());

        ll right = m-1;
        ll left = 0;
        ll cnt = 0;
        ll ans = 0;
        for (int i=n-2 ; i>-1 ; i--) {
            ll leftToFill = i+1;
            ll rightToFill = n-leftToFill;

            while(right > -1 && (v[right] >= leftToFill)) {
                cnt++;
                right--;
            }

            while(left < m && v[left] < rightToFill)
                left++;

            ll cntR = m-left;

            ll duplicated = m - max(left, right+1);

            ans += cntR * cnt - duplicated;
        }
        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}