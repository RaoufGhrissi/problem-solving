#include <bits/stdc++.h>
#define loop(n) for (int i=0 ; i<n ; i++)
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))
#define sortDesc(v) sort(all(v), greater<int>())

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        vector<int> v(n);
        loop(n) cin>>v[i];

        sortt(v);

        int i = n%2 ? n/2 + 1 : n/2;
        i--;
        int j = i+1;
        int ans = 1;
        while(j<n && v[j] == v[i]) {
            ans++;
            j++;
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}