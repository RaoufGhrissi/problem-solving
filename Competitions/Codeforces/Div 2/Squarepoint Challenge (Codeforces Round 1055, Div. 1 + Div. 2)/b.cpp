#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, ll>

using namespace std;

void no() {
    cout<<"NO"<<endl;
}

void yes() {
    cout<<"YES"<<endl;
}

void solve() {
#ifndef ONLINE_JUDGE
    freopen("a.txt", "r", stdin);
#endif
    int t;
    cin>>t;

    while(t--) {
        int n, x, y, a, b;
        cin>>n>>x>>y>>a>>b;
        
        int ans = 0;
		if (x < a)  
			ans = max(ans, a);
		if (x > a)
			ans = max(ans, n - a);
		if (y < b)
			ans = max(ans, b);
		if (y > b)
			ans = max(ans, n - b);

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}