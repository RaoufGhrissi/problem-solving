#include <bits/stdc++.h>

using namespace std;

void solve() {
    freopen("a.txt", "r", stdin);
    int t;
    cin>>t;

    while(t--) {
        string s;
        cin>>s;

        int n = s.size();
        int ans = 1;
        bool taken = 0;

        for (int i=1 ; i<n ; i++) {
            if (s[i] != s[i-1]) {
                if (s[i] == '1' && !taken) {
                    taken = 1;
                    continue;
                }
                ans++;
            }
        }

        cout<<ans<<endl;
    }
}

int main() {
    solve();
    return 0;
}