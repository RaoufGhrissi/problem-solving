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
        string s;
        cin>>s;

        int n = s.size();

        int ans = 0;
        bool found = 0;
        for (int i=n-1 ; i>-1 ; i--) {
            if (found) {
                ans += s[i] != '0';
            } else {
                if (s[i] == '0') ans++;
                else found = 1;
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}